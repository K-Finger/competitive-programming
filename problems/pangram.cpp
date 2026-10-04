#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; string s;
    cin >> n >> s;

    set<char> seen;
    for (char c : s) seen.insert(tolower(c));

    cout << (seen.size() == 26 ? "YES" : "NO") << "\n";
}
