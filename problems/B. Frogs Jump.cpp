#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    string r1, r2;
    cin >> r1 >> r2;

    ll cnt = count(r1.begin(), r1.end(), 'f');
    cnt += count(r2.begin(), r2.end(), 'f');

    cout << (cnt % 2 == 0 ? 0 : 1) << '\n';
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
