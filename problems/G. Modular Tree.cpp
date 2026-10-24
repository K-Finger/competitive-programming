#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> a(x);
    for (int i = 0; i < x; i++) {
        cin >> a[x];
    }

    vector<int> b(y);
    for (int i = 0; i < y; i++) {
        cin >> b[y];
    }

    int totalNeeded = n + m - 1;
    int da = (n - 1);
    int db = (m - 1);

    int ra = x - 1;
    int rb = y - 1;

    while (da > 0 && db > 0) {
        if (da > db) {
            // select from a

        } else if (da < db) {

        } else {
            // select lowest one before
        }
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
