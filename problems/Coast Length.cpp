#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool inBounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> map(n + 2, vector<bool>(m + 2, false));

    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        for (int j = 1; j <= m; j++) {
            map[i][j] = s[j - 1] == '1';
        }
    }

    n += 2;
    m += 2;

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    int ans = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (!inBounds(nx, ny, n, m))
                continue;

            if (map[nx][ny]) {
                ans++;
                continue;
            }

            if (!visited[nx][ny]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;

    while (t--) {
        solve();
    }
}
