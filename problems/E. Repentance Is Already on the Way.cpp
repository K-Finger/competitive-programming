#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n), b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    auto weight = [&](ll x, ll y) {
        return (x == y ? 2LL : 1LL);
    };

    ll curr = 0;

    for (int i = 0; i < n; i++) {
        curr += weight(a[i], b[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        curr += weight(a[i + 1], b[i]);
    }

    ll ans = curr;

    for (int i = n - 2; i >= 0; i--) {
        curr -= weight(a[i], b[i]);
        curr += weight(a[i], b[i + 1]);

        ans = max(ans, curr);
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
