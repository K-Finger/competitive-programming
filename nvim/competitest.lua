-- competitest.nvim spec (lazy.nvim), shared across machines.
-- Install: symlink/copy to ~/.config/nvim/lua/plugins/competitest.lua
--   Linux:   ln -s ~/competitive-programming/nvim/competitest.lua ~/.config/nvim/lua/plugins/
--   Windows: copy to %LOCALAPPDATA%\nvim\lua\plugins\

local is_win = vim.fn.has("win32") == 1

-- First existing repo location wins
local root
for _, p in ipairs({
  "~/competitive-programming",
  "~/OneDrive/Desktop/competitive-programming",
  "~/Desktop/competitive-programming",
}) do
  local dir = vim.fn.expand(p)
  if vim.fn.isdirectory(dir) == 1 then
    root = dir
    break
  end
end
root = root or vim.fn.expand("~/competitive-programming")

return {
  "xeluxee/competitest.nvim",
  dependencies = "MunifTanjim/nui.nvim",
  cmd = "CompetiTest",
  config = function()
    require("competitest").setup({
      compile_command = {
        cpp = { exec = "g++", args = { "-std=c++20", "-O2", "-Wall", "-Wextra", "$(FNAME)", "-o", "$(FNOEXT)" } },
      },
      run_command = { cpp = { exec = is_win and "$(FNOEXT).exe" or "./$(FNOEXT)" } },
      received_problems_path = root .. "/problems/$(PROBLEM).$(FEXT)",
      template_file = root .. "/templates/templates.cpp",
    })
  end,
  keys = {
    { "<leader>cr", "<cmd>CompetiTest run<cr>", desc = "Run testcases" },
    { "<leader>ca", "<cmd>CompetiTest add_testcase<cr>", desc = "Add testcase" },
    { "<leader>ce", "<cmd>CompetiTest edit_testcase<cr>", desc = "Edit testcase" },
    { "<leader>cd", "<cmd>CompetiTest delete_testcase<cr>", desc = "Delete testcase" },
    { "<leader>cp", "<cmd>CompetiTest receive problem<cr>", desc = "Receive problem" },
  },
}
