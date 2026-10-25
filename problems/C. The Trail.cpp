#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    vector<vector<ll>> grid(n, vector<ll>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int x = 0;
    int y = 0;

    for (char c : s) {
        if (c == 'D') {
            ll sum = 0;
            for (int j = 0; j < m; j++) {
                sum += grid[x][j];
            }
            grid[x][y] = -sum;
            x++;
        }
        else {
            ll sum = 0;
            for (int i = 0; i < n; i++) {
                sum += grid[i][y];
            }
            grid[x][y] = -sum;
            y++;
        }
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += grid[i][m - 1];
    }
    grid[n - 1][m - 1] = -sum;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];

            if (j != m - 1) {
                cout << ' ';
            }
            else {
                cout << '\n';
            }
        }
    }
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
