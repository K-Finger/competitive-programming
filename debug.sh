#!/usr/bin/env bash
# Debug Build - sanitizers enabled (AddressSanitizer + UBSan)
# Usage: ./debug.sh solution.cpp [input.txt]
# Input defaults to input.txt next to the source file.

set -euo pipefail

src=${1:?Usage: ./debug.sh solution.cpp [input.txt]}
input=${2:-"$(dirname "$src")/input.txt"}
build_dir="$(cd "$(dirname "$0")" && pwd)/build"
exe="$build_dir/$(basename "${src%.*}")_debug"

mkdir -p "$build_dir"

# Sanitizers need libasan/libubsan (sudo dnf install libasan libubsan)
sanitize=(-fsanitize=address,undefined)
if ! echo 'int main(){}' | g++ -x c++ "${sanitize[@]}" -o /dev/null - 2>/dev/null; then
    echo -e "\e[33mSanitizer libs missing, building without them (sudo dnf install libasan libubsan)\e[0m"
    sanitize=()
fi

echo -e "\e[33mDebug compiling $src...\e[0m"
if g++ -std=c++20 -g -O0 -Wall -Wextra -Wshadow \
    -D_GLIBCXX_DEBUG -DLOCAL "${sanitize[@]}" \
    -o "$exe" "$src"; then
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
