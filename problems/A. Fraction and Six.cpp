#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string p, q;
    cin >> p >> q;

    map<char, int> freq;
    for (char c : q) {
        freq[c]++;
    }

    string ans = "";
    for (char c : p) {
        if (freq.count(c)) {
            freq[c]--;
            if (freq[c] == 0) {
                freq.erase(c);
            }
        } else {
            ans.push_back(c);
        }
    }

    sort(ans.begin(), ans.end());
    cout << (ans == "isx" && freq.empty() ? "YES" : "NO") << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
