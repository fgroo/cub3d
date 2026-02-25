# Teamtype Collaboration Guide (Neovim)

Live-Collaboration mit VS Code - peer-to-peer, keine Cloud, kein sudo nötig.

## Einrichtung

### 1. CLI installieren

```bash
curl -sL https://github.com/teamtype/teamtype/releases/latest/download/teamtype-x86_64-unknown-linux-musl.tar.gz | tar xzf - -C /tmp
mkdir -p ~/.local/bin
mv /tmp/teamtype ~/.local/bin/
chmod +x ~/.local/bin/teamtype
echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.bashrc
source ~/.bashrc
```

### 2. Neovim Plugin (lazy.nvim)

In `~/.config/nvim/lua/plugins/` eine Datei erstellen:

```lua
return {
  {
    "teamtype/teamtype-nvim",
    config = true,
  },
}
```

## Session beitreten

```bash
cd ~/coding/projects/cub3d
teamtype join 1-december-ammo
```

Dann in Neovim die Datei öffnen - Änderungen syncen live mit VS Code.

## Links

- https://github.com/teamtype/teamtype
- https://github.com/teamtype/teamtype-nvim
