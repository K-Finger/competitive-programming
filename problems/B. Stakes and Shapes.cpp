#include <bits/stdc++.h>
using namespace std;
using ll = long long;


void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    ll n = x + y + z;

    if (x >= y && x >= z) {
        cout << string(n, 'P') << '\n';
    }
    else if (y >= x && y >= z) {
        cout << string(n, 'R') << '\n';
    }
    else {
        cout << string(n, 'S') << '\n';
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
