#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> odd, even;

    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    sort(odd.rbegin(), odd.rend());
    sort(even.rbegin(), even.rend());

    int a = odd.size();
    int b = even.size();

    vector<ll> pref(b + 1, 0);
    for (int i = 0; i < b; i++) {
        pref[i + 1] = pref[i] + even[i];
    }

    for (int k = 1; k <= n; k++) {
        ll ans = 0;

        if (a > 0) {
            int takeEven = min(b, k - 1);
            int takeOdd = k - takeEven;

            if (takeOdd % 2 == 0) {
                takeEven--;
                takeOdd++;
            }

            if (takeEven >= 0 && takeOdd <= a) {
                ans = odd[0] + pref[takeEven];
            }
        }

        cout << ans << (k == n ? '\n' : ' ');
    }
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
