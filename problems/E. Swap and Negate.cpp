#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string init, targ;
    cin >> init >> targ;

    vector<int> parent(n + 1, 0);
    vector<int> carry(n + 1, 0);

    vector<int> curr = {1};
    parent[1] = -1;

    ll ans = 0;
    ll power = 1;

    while (!curr.empty()) {
        int bit = -1;

        for (int u : curr) {
            int x = init[u - 1] - '0';
            int y = targ[u - 1] - '0';

            int need = x ^ y ^ carry[u];

            if (bit != -1 && bit != need) {
                cout << -1 << '\n';
                return;
            }

            bit = need;
        }

        ans = (ans + power * bit) % MOD;

        vector<int> nxt;

        for (int u : curr) {
            int x = init[u - 1] - '0';
            int c = (bit + carry[u] + x) / 2;

            for (int v : adj[u]) {
                if (v == parent[u]) continue;

                parent[v] = u;
                carry[v] = c;
                nxt.push_back(v);
            }
        }

        curr.swap(nxt);
        power = power * 2 % MOD;
    }

    cout << ans << '\n';
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
