# competitive-programming

- `problems/` — solutions + competitest testcases (`*_input0.txt`, `*_output0.txt`)
- `templates/templates.cpp`, `templates/template.py` — templates for new problems (`<leader>cp` asks C++ or Python)
- `nvim/competitest.lua` — competitest.nvim plugin spec (`<leader>cp` receives a problem into `problems/`)
- `run.sh` / `debug.sh` (Linux), `run.ps1` / `debug.ps1` / `run.bat` (Windows)

## Setup on a new machine

Link the nvim spec into your lazy.nvim plugins dir:

```sh
# Linux
ln -sf ~/competitive-programming/nvim/competitest.lua ~/.config/nvim/lua/plugins/competitest.lua
```

```powershell
# Windows (admin or developer mode for symlinks; otherwise just copy)
New-Item -ItemType SymbolicLink -Force -Path "$env:LOCALAPPDATA\nvim\lua\plugins\competitest.lua" -Target "$HOME\OneDrive\Desktop\competitive-programming\nvim\competitest.lua"
```
