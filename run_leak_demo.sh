#!/usr/bin/env bash

# Paths relative to the script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
MLX_DIR="${SCRIPT_DIR}/MLX42"
MLX_BUILD="${MLX_DIR}/build"
SUPP_FILE="${SCRIPT_DIR}/cub3d.supp"

# 1. Build MLX42 if it does not exist
if [ ! -f "${MLX_BUILD}/libmlx42.a" ]; then
    echo "--- Building MLX42... ---"
    cmake -S "${MLX_DIR}" -B "${MLX_BUILD}"
    make -C "${MLX_BUILD}" -j4
fi

# 2. Compile leak_demo.c
echo "--- Compiling leak_demo.c... ---"
gcc leak_demo.c \
    -I"${MLX_DIR}/include/MLX42" \
    -L"${MLX_BUILD}" \
    -lmlx42 -lglfw -lm -ldl -lpthread \
    -o leak_demo

# 3. Use valgrind to check for leaks
if [ $? -eq 0 ]; then
    echo "--- Running leak_demo with valgrind... ---"
    # Using the project's suppression file if it exists
    if [ -f "${SUPP_FILE}" ]; then
        VALGRIND_SUPP="--suppressions=${SUPP_FILE}"
    else
        VALGRIND_SUPP=""
    fi
    
    valgrind \
        --leak-check=full \
        --show-leak-kinds=all \
        --track-origins=yes \
        ${VALGRIND_SUPP} \
        ./leak_demo
else
    echo "Compilation failed."
fi
