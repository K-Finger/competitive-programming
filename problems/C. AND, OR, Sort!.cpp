
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll maximumValue(ll current, ll mod, ll step) {
    if (step == 0) return current;

    ll remaining = mod - 1 - current;
    return current + (remaining / step) * step;
}

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    vector<vector<int>> tree(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> parent(n + 1, -1);
    vector<int> order;

    order.push_back(1);
    parent[1] = 0;

    for (int i = 0; i < (int)order.size(); i++) {
        int u = order[i];

        for (int v : tree[u]) {
            if (v == parent[u]) continue;

            parent[v] = u;
            order.push_back(v);
        }
    }

    vector<ll> step(n + 1, 0);
    ll answer = 0;

    for (int i = n - 1; i >= 0; i--) {
        int u = order[i];

        ll childSum = 0;
        ll common = b[u];

        for (int v : tree[u]) {
            if (parent[v] != u) continue;

            childSum += a[v];
            common = gcd(common, step[v]);
        }

        common = gcd(common, childSum);

        if (common != b[u]) {
            step[u] = common;
        }

        answer += maximumValue(a[u], b[u], step[u]);
    }

    cout << answer << '\n';
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