#!/usr/bin/env bash
# Competitive Programming Quick Build/Run Script
# Usage: ./run.sh solution.cpp [input.txt]
# Input defaults to input.txt next to the source file.

set -euo pipefail

src=${1:?Usage: ./run.sh solution.cpp [input.txt]}
input=${2:-"$(dirname "$src")/input.txt"}
build_dir="$(cd "$(dirname "$0")" && pwd)/build"
exe="$build_dir/$(basename "${src%.*}")"

mkdir -p "$build_dir"

echo -e "\e[36mCompiling $src...\e[0m"
if g++ -std=c++20 -O2 -Wall -Wextra -Wshadow -o "$exe" "$src"; then
    echo -e "\e[32mRunning...\e[0m"
    if [[ -f $input ]]; then
        "$exe" < "$input"
    else
        "$exe"
    fi
else
    echo -e "\e[31mCompilation failed!\e[0m"
    exit 1
fi
