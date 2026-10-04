#!/usr/bin/env python3
"""
Competitive Companion receiver for Neovim integration.
Listens on port 10043 for problems from browser extension.

Usage: python companion.py
Then parse problem in browser with competitive-companion extension.

Install extension: https://github.com/jmerle/competitive-companion
"""

import http.server
import json
import os
import re
import subprocess
import sys
from pathlib import Path

PORT = 10043
PROBLEMS_DIR = Path(__file__).parent / "problems"
TEMPLATE = Path(__file__).parent / "templates" / "templates.cpp"


def sanitize_name(name: str) -> str:
    """Convert problem name to valid filename."""
    # Remove special chars, keep alphanumeric and spaces
    name = re.sub(r'[^\w\s\-.]', '', name)
    name = re.sub(r'\s+', '_', name.strip())
    return name[:50]  # Limit length


def create_problem(data: dict) -> Path:
    """Create problem file and input from competitive-companion data."""
    name = data.get("name", "problem")
    filename = sanitize_name(name) + ".cpp"
    filepath = PROBLEMS_DIR / filename
    inputpath = PROBLEMS_DIR / "input.txt"

    # Read template
    template_content = ""
    if TEMPLATE.exists():
        template_content = TEMPLATE.read_text()
    else:
        template_content = """#include <bits/stdc++.h>
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
"""

    # Add problem URL as comment
    url = data.get("url", "")
    if url:
        template_content = f"// {url}\n\n" + template_content

    # Write solution file (don't overwrite existing)
    if not filepath.exists():
        filepath.write_text(template_content)
        print(f"Created: {filepath}")
    else:
        print(f"Exists: {filepath}")

    # Write test input (first test case)
    tests = data.get("tests", [])
    if tests:
        input_text = tests[0].get("input", "")
        inputpath.write_text(input_text)
        print(f"Input: {inputpath}")

        # Also save all test cases
        all_tests = PROBLEMS_DIR / f"{sanitize_name(name)}_tests.txt"
        test_content = ""
        for i, test in enumerate(tests, 1):
            test_content += f"=== Test {i} ===\nInput:\n{test.get('input', '')}\nExpected:\n{test.get('output', '')}\n\n"
        all_tests.write_text(test_content)

    return filepath


class CompanionHandler(http.server.BaseHTTPRequestHandler):
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        body = self.rfile.read(content_length).decode('utf-8')

        try:
            data = json.loads(body)
            filepath = create_problem(data)

            # Open in nvim (optional - comment out if not wanted)
            # subprocess.Popen(["nvim", str(filepath)])

            self.send_response(200)
            self.end_headers()
            self.wfile.write(b"OK")

            print(f"\nProblem: {data.get('name')}")
            print(f"URL: {data.get('url')}")
            print(f"Tests: {len(data.get('tests', []))}")
            print("-" * 40)

        except Exception as e:
            print(f"Error: {e}")
            self.send_response(500)
            self.end_headers()

    def log_message(self, format, *args):
        pass  # Suppress default logging


def main():
    PROBLEMS_DIR.mkdir(exist_ok=True)

    server = http.server.HTTPServer(("127.0.0.1", PORT), CompanionHandler)
    print(f"Competitive Companion listener on port {PORT}")
    print(f"Problems dir: {PROBLEMS_DIR}")
    print("Waiting for problems... (Ctrl+C to stop)")
    print("-" * 40)

    try:
        server.serve_forever()
    except KeyboardInterrupt:
        print("\nStopped.")
        server.shutdown()


if __name__ == "__main__":
    main()
