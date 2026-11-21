#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (auto& v : a) cin >> v;

    auto check = [&](ll k) {
        vector<ll> isolated;

        for (int i = 0; i < n; i++) {
            bool left = i > 0 && a[i] - a[i - 1] <= k;
            bool right = i + 1 < n && a[i + 1] - a[i] <= k;

            if (!left && !right) {
                isolated.push_back(a[i]);
            }
        }

        int used = 0;

        for (int i = 0; i < (int)isolated.size(); i++) {
            used++;

            if (i + 1 < (int)isolated.size() &&
                isolated[i + 1] - isolated[i] <= 2 * k) {
                i++;
            }
        }

        return used <= x;
    };

    ll l = 1, r = 1000000000;

    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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
