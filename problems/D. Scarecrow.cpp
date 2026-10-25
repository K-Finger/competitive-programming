
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

pair<ll, ll> f(ll p, ll t, ll ai, ll k) {
    ll Pnew = p;
    ll Tnew = t;

    if (ai - t > p) {
        ll d = ai - t - p;
        ll dt = d / 2;

        Pnew = p + dt + k;
        Tnew = t + dt;
    }
    else if (ai - t <= p && p <= ai + t) {
        Pnew = p + k;
    }
    else {
        Pnew = max(p, ai + t + k);
    }

    return {Pnew, Tnew};
}

void solve() {
    int n;
    ll k, l;
    cin >> n >> k >> l;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }

    k *= 2;
    l *= 2;

    ll t = a[0];
    ll p = k;
    ll ans = t + max(0LL, l - p);

    for (int i = 1; i < n; i++) {
        auto [Pnew, Tnew] = f(p, t, a[i], k);

        p = Pnew;
        t = Tnew;

        ans = min(ans, t + max(0LL, l - p));

        if (p >= l) {
            break;
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
