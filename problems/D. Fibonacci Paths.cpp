#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static constexpr ll MOD = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> adj(n), rev(n);
    vector<int> from(m), to(m);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        from[i] = u;
        to[i] = v;

        adj[u].push_back(i);
        rev[v].push_back(i);
    }

    vector<int> order(n);
    iota(order.begin(), order.end(), 0);

    sort(order.begin(), order.end(), [&](int x, int y) {
        return a[x] > a[y];
    });

    vector<ll> dp(m, 0);
    ll ans = 0;

    for (int v : order) {
        unordered_map<ll, ll> sums;
        sums.reserve(adj[v].size() * 2 + 1);

        for (int id : adj[v]) {
            ll val = a[to[id]];
            sums[val] = (sums[val] + dp[id]) % MOD;
        }

        for (int id : rev[v]) {
            int u = from[id];

            ll target = a[u] + a[v];
            dp[id] = (1 + sums[target]) % MOD;

            ans = (ans + dp[id]) % MOD;
        }
    }

    cout << ans << '\n';
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
