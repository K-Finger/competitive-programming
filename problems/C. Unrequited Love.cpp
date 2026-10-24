#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll ans = 0;
    unordered_map<int, ll> seenLove;
    vector<int> love(n - 4);

    for (int i = 0; i < n - 4; i++) {
        love[i] = a[i] + a[i + 2] - a[i + 4];

        ans += seenLove[love[i]];

        if (i >= 2 && love[i - 2] == love[i])
            ans--;

        if (i >= 4 && love[i - 4] == love[i])
            ans--;

        seenLove[love[i]]++;
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
}
