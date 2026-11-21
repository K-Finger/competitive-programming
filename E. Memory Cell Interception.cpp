#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    string s, t;
    cin >> s >> t;

    auto calc = [&](string &a, string &b) {
        int n = a.size(), m = b.size();

        vector<int> pos;
        for (int i = 0; i < m; i++) {
            if (b[i] == 'W') pos.push_back(i + 1);
        }

        vector<int> freq(max(n, m) + 1, 0);

        for (int i = 1; i < (int)pos.size(); i++) {
            freq[pos[i] - pos[i - 1]]++;
        }

        vector<int> ways(n + 1, 1);

        if (!pos.empty()) {
            int active = (int)pos.size() - 1;
            ways[1] = pos.size() + 1;

            for (int i = 2; i <= n; i++) {
                active -= freq[i - 1];
                ways[i] = ways[i - 1] + 1 + active;
            }
        }

        int last = pos.empty() ? 0 : pos.back();
        int prev = 0;

        for (int i = 1; i <= n; i++) {
            if (a[i - 1] == 'W') {
                prev = i;
                continue;
            }

            int ans;

            if (prev == 0) {
                ans = ways[i];
            } else {
                ans = m + 1;

                if (last > 0) {
                    ans = max(ans, last + i - prev);
                }
            }

            cout << ans << " ";
        }

        cout << '\n';
    };

    calc(s, t);
    calc(t, s);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
