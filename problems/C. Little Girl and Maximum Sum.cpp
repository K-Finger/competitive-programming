#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n, q;
    cin >> n >> q;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> k(n + 2, 0); 
    for (int i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        k[l]++;
        k[r + 1]--;
    }

    for (int i = 1; i <= n; i++) {
        k[i] = k[i-1] + k[i];
    }

    sort(k.begin() + 1, k.begin() + n + 1);
    sort(a.begin(), a.end());

    ll p = 0;
    for (int i = 0; i < n; i++) {
        p += a[i] * k[i + 1];
    }

    cout << p << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
