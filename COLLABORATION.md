# Teamtype Collaboration Guide

Live-Collaboration zwischen verschiedenen Editoren (VS Code + Neovim) - peer-to-peer, keine Cloud.

## Einrichtung

### 1. CLI installieren

**Option A: Binary (empfohlen)**
```bash
curl -sL https://github.com/teamtype/teamtype/releases/latest/download/teamtype-x86_64-unknown-linux-musl.tar.gz | tar xzf - -C /tmp
mkdir -p ~/.local/bin
mv /tmp/teamtype ~/.local/bin/
chmod +x ~/.local/bin/teamtype
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

**Option B: Mit Cargo**
```bash
cargo install teamtype
```

### 2. VS Code Extension

Im Marketplace nach **"Teamtype"** suchen und installieren.

## Session starten

**Host (der shared):**
```bash
cd /pfad/zum/projekt
teamtype share
```
→ Join-Code wird angezeigt (z.B. `5-hamburger-endorse`)

**Gast (der joined):**
```bash
cd /pfad/zum/projekt
teamtype join 5-hamburger-endorse
```

Danach einfach Datei in VS Code öffnen - Änderungen syncen live.

## Links

- https://github.com/teamtype/teamtype
- https://github.com/teamtype/teamtype-nvim (für Neovim-User)
