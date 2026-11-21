#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (ll& x : a) {
        cin >> x;
    }

    // 8 8 7 2 3 3 2 4 2
    // 7 7 6 2 2 2 2 3 2
    // 7 7 7 3 3 3 3 4 3
    // 7 7 7 4 4 4 4 5 4
    // 7 7 7 5 5 5 5 6 5
    // 7 7 7 6 6 6 6 7 6
    // 7 7 7 7 7 7 7 7 7

    sort(a.begin(), a.end());

    ll med = a[n / 2];
    ll cost = 0;

    for (ll x : a) {
        cost += abs(x - med);
    }

    ll ops = a[n - 1] - a[0];

    cout << cost << " " << ops << '\n';
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
