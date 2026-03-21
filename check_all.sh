#!/bin/bash
MAPS_DIR="maps/debug"
EXE="./cub3d"
SUPP="cub3d.supp"

echo "Checking all maps in $MAPS_DIR and maps/*.cub..."

for m in $(find "$MAPS_DIR" -maxdepth 1 -name "*.cub" | sort) maps/basic.cub maps/example.cub; do
    echo -n "Map: $m -> "
    # Run with 30s timeout because Valgrind/MLX is slow
    timeout 30s valgrind --leak-check=full --show-leak-kinds=definite --suppressions="$SUPP" "$EXE" "$m" > /tmp/val_out 2>&1
    RET=$?
    
    if [ $RET -eq 124 ]; then
        echo -n "TIMEOUT! (30s) "
    fi
    
    # Check if we have definitely lost bytes > 0
    # Note: Valgrind output format: "==pid==    definitely lost: X bytes in Y blocks"
    LOST=$(grep "definitely lost:" /tmp/val_out | awk '{print $4}' | tr -d ',')
    
    if [[ -z "$LOST" ]]; then
       # No summary found? Maybe process crashed without Valgrind summary.
       # Check if we see "0 bytes" anywhere.
       if grep -q "0 bytes in 0 blocks" /tmp/val_out; then
           echo "CLEAN ✅"
       else
           echo "NO SUMMARY (CRASH?) ⚠️"
       fi
    elif [[ "$LOST" -gt 0 ]]; then
        echo "FAIL ❌ ($LOST bytes)"
        grep -A 5 "definitely lost:" /tmp/val_out
    else
        echo "CLEAN ✅"
    fi
done

echo "Done."
