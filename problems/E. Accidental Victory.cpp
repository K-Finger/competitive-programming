#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static constexpr ll MOD = 998244353;

void solve() {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> a(n);
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        a[i] = {x, i};
    }

    sort(a.begin(), a.end());

    vector<ll> prefix(n+1, a[0].first);
    for (size_t i = 1; i < n; i++) {
        prefix[i] = a[i].first + prefix[i-1];
    }

    int cutoff = n - 1;
    for (int i = n - 2; i >= 0; i--) {
        if (prefix[i] >= a[i+1].first) {
            cutoff = i;
        }
        else {
            break;
        }
    }

    vector<ll> ans;
    for (int i = cutoff; i < n; i++) {
        ans.push_back(a[i].second + 1);
    }

    sort (ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << ' ';
        }
    }

    cout << '\n';
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
