#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 4e18;

ll cost(ll a, ll b, ll c, ll target) {
    ll sum = a + b + c;

    if (sum >= target)
        return 0;

    if (a > b || a > c || b > c)
        return target - sum;

    if (a == b && b == c)
        return INF;

    ll setup = INF;

    if (a < c)
        setup = min(setup, b - a + 1);

    if (a < b)
        setup = min(setup, c - b + 1);

    return target - sum + 2 * setup;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<array<ll, 3>> labs(n);

    ll mn = INF;

    for (int i = 0; i < n; i++) {
        cin >> labs[i][0] >> labs[i][1] >> labs[i][2];

        ll sum = labs[i][0] + labs[i][1] + labs[i][2];
        mn = min(mn, sum);
    }

    ll l = mn;
    ll r = mn + k + 1;

    while (l < r) {
        ll mid = l + (r - l + 1) / 2;

        ll used = 0;

        for (int i = 0; i < n; i++) {
            ll curr = cost(
                labs[i][0],
                labs[i][1],
                labs[i][2],
                mid
            );

            if (curr >= INF || used > k - curr) {
                used = k + 1;
                break;
            }

            used += curr;
        }

        if (used <= k)
            l = mid;
        else
            r = mid - 1;
    }

    cout << l << '\n';
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
