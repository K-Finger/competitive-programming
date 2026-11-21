#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> x(n);
    vector<ll> h(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> h[i];
    }

    int a = 1;
    ll p = INT_MIN;
    for (int i = 0; i < n - 1; i++) {
        if ((x[i] - h[i]) > p) {
            p = x[i];
            a++;
        }
        else if ((x[i]+ h[i]) < x[i+1]) {
            p = x[i] + h[i];
            a++;
        }
        else {
            p = x[i];
        }
    }

    cout << a << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
