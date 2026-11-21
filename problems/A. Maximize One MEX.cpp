#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto& x : a) cin >> x;

    int r = n - k + 1;

    vector<int> seen(n + 1, 0);
    for (int i = 0; i < r; i++) {
        seen[a[i]] = 1;
    }

    int mex = 0;
    while (seen[mex]) mex++;

    if (mex == r) {
        cout << -1 << '\n';
        return;
    }

    int x = 0, y = 0;

    for (int i = 0; i < r; i++) {
        if (a[i] > a[x]) x = i;
    }

    for (int i = r; i < n; i++) {
        if (a[i] == mex) {
            y = i;
            break;
        }
    }

    cout << x + 1 << " " << y + 1 << '\n';
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
