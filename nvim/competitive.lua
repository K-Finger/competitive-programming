-- Competitive Programming Neovim Config
-- Add to your init.lua: require('competitive')
-- Or source directly: luafile path/to/competitive.lua

local M = {}

-- Config
local problems_dir = vim.fn.expand("~/OneDrive/Desktop/competitive-programming/problems")
local template_file = vim.fn.expand("~/OneDrive/Desktop/competitive-programming/templates/templates.cpp")

-- Compile and run current file
function M.compile_run()
    vim.cmd("write")
    local file = vim.fn.expand("%:p")
    local name = vim.fn.expand("%:t:r")
    local dir = vim.fn.expand("%:p:h")
    local input = dir .. "/input.txt"

    local cmd
    if vim.fn.filereadable(input) == 1 then
        cmd = string.format(
            "g++ -std=c++20 -O2 -Wall -o %s/%s.exe %s && %s/%s.exe < %s",
            dir, name, file, dir, name, input
        )
    else
        cmd = string.format(
            "g++ -std=c++20 -O2 -Wall -o %s/%s.exe %s && %s/%s.exe",
            dir, name, file, dir, name
        )
    end

    vim.cmd("split | terminal " .. cmd)
end

-- Debug compile with sanitizers
function M.compile_debug()
    vim.cmd("write")
    local file = vim.fn.expand("%:p")
    local name = vim.fn.expand("%:t:r")
    local dir = vim.fn.expand("%:p:h")
    local input = dir .. "/input.txt"

    local compile = string.format(
        "g++ -std=c++20 -g -O0 -Wall -Wextra -Wshadow -D_GLIBCXX_DEBUG -DLOCAL -o %s/%s.exe %s",
        dir, name, file
    )

    local run
    if vim.fn.filereadable(input) == 1 then
        run = string.format("%s/%s.exe < %s", dir, name, input)
    else
        run = string.format("%s/%s.exe", dir, name)
    end

    vim.cmd("split | terminal " .. compile .. " && " .. run)
end

-- Create new problem from template
function M.new_problem(name)
    if not name or name == "" then
        name = vim.fn.input("Problem name: ")
    end
    if name == "" then return end

    local filename = problems_dir .. "/" .. name:gsub("%s+", "_") .. ".cpp"

    if vim.fn.filereadable(filename) == 1 then
        print("File exists: " .. filename)
        vim.cmd("edit " .. filename)
        return
    end

    -- Copy template
    if vim.fn.filereadable(template_file) == 1 then
        vim.fn.system(string.format('cp "%s" "%s"', template_file, filename))
    else
        -- Fallback template
        local f = io.open(filename, "w")
        f:write([[#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()

void solve() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}
]])
        f:close()
    end

    vim.cmd("edit " .. filename)
    print("Created: " .. filename)
end

-- Open input.txt in split
function M.open_input()
    local dir = vim.fn.expand("%:p:h")
    local input = dir .. "/input.txt"
    vim.cmd("vsplit " .. input)
end

-- Setup keymaps
function M.setup()
    local opts = { noremap = true, silent = true }

    -- F5: Compile and run
    vim.keymap.set("n", "<F5>", M.compile_run, opts)

    -- F6: Debug compile and run
    vim.keymap.set("n", "<F6>", M.compile_debug, opts)

    -- F7: New problem
    vim.keymap.set("n", "<F7>", M.new_problem, opts)

    -- F8: Open input.txt
    vim.keymap.set("n", "<F8>", M.open_input, opts)

    -- Leader mappings
    vim.keymap.set("n", "<leader>cr", M.compile_run, opts)
    vim.keymap.set("n", "<leader>cd", M.compile_debug, opts)
    vim.keymap.set("n", "<leader>cn", M.new_problem, opts)
    vim.keymap.set("n", "<leader>ci", M.open_input, opts)

    print("Competitive programming keymaps loaded!")
end

-- Commands
vim.api.nvim_create_user_command("CPRun", M.compile_run, {})
vim.api.nvim_create_user_command("CPDebug", M.compile_debug, {})
vim.api.nvim_create_user_command("CPNew", function(opts) M.new_problem(opts.args) end, { nargs = "?" })
vim.api.nvim_create_user_command("CPInput", M.open_input, {})

return M
