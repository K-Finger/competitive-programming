return {
  "xeluxee/competitest.nvim",
  dependencies = "MunifTanjim/nui.nvim",
  cmd = "CompetiTest",
  config = function()
    require("competitest").setup({
      compile_command = {
        cpp = { exec = "g++", args = { "-std=c++20", "-O2", "-Wall", "-Wextra", "$(FNAME)", "-o", "$(FNOEXT)" } },
      },
      run_command = { cpp = { exec = "./$(FNOEXT)" } },
      received_problems_path = "$(HOME)/competitive-programming/problems/$(PROBLEM).$(FEXT)",
      template_file = "$(HOME)/competitive-programming/templates/templates.cpp",
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
