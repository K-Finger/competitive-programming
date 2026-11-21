#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int k;
    cin >> k;

    vector<int> hub(k + 1, 1);
    int center = -1;

    for (int i = 1; i <= k; i++) {
        int n;
        cin >> n;

        vector<int> deg(n + 1, 0);
        vector<int> neighbor(n + 1, 0);

        for (int j = 0; j < n - 1; j++) {
            int u, v;
            cin >> u >> v;

            deg[u]++;
            deg[v]++;

            neighbor[u] = v;
            neighbor[v] = u;
        }

        if (n == 1) continue;

        if (center == -1) center = i;

        for (int j = 1; j <= n; j++) {
            if (deg[j] == 1) {
                hub[i] = neighbor[j];
                break;
            }
        }
    }

    if (center == -1) {
        for (int i = 2; i <= k; i++) {
            cout << 1 << " " << 1 << " "
                 << i << " " << 1 << '\n';
        }
        return;
    }

    for (int i = 1; i <= k; i++) {
        if (i == center) continue;

        cout << center << " " << hub[center] << " "
             << i << " " << hub[i] << '\n';
    }
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
