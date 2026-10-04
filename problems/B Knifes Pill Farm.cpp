#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

const ll MOD = 998244353;
const int MAXN = 200000;

ll inv[MAXN + 1];

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    // T = (n - 1)!
    ll totalTrees = 1;

    for (int i = 1; i <= n - 1; i++) {
        totalTrees = totalTrees * i % MOD;
    }

    ll prefixSum = a[0] % MOD;
    ll ans = 0;

    // i is 0-based:
    // a[i] has i possible parents
    for (int i = 1; i < n; i++) {

        // (a[0] + ... + a[i-1]) - i * a[i]
        ll edgeSum =
            (prefixSum - (1LL * i * (a[i] % MOD)) % MOD + MOD) % MOD;

        // Each possible edge from a[i] appears T / i times
        ll times =
            totalTrees * inv[i] % MOD;

        ans =
            (ans + times * edgeSum) % MOD;

        prefixSum =
            (prefixSum + a[i]) % MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // Modular inverses
    inv[1] = 1;

    for (int i = 2; i <= MAXN; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}