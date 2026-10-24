#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int n, k;
    cin >> n >> k;
    
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    ll ans = 0;
    int r = n - k + 1;
    int pairs = min(r, k - 1);
    for (int i = 0; i < pairs; i++) {
        ans += max(a[i], a[n - 1 - i]);
    }

    if (n >= 2 * k - 1) {
        for (int i = k - 1; i <= n - k; i++) {
            ans += a[i];
        }
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

    return 0;
}
