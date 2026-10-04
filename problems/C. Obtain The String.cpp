#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool inBounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();

    // next[i][c] = next occurrence of character c starting from position i in s
    vector<vector<int>> nxt(n + 1, vector<int>(26, -1));

    for (int i = n - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nxt[i][c] = nxt[i + 1][c];
        }
        nxt[i][s[i] - 'a'] = i;
    }

    int ans = 1;
    int pos = 0;
    for (char c : t) {
        if (nxt[0][c - 'a'] == -1) {
            cout << -1 << "\n";
            return;
        }
        if (nxt[pos][c - 'a'] == -1) {
            ans++;
            pos = 0;
        }
        pos = nxt[pos][c - 'a'] + 1;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
