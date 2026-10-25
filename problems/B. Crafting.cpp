#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int deficit_count = 0;
    ll required_operations = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] < b[i]) {
            deficit_count++;
            required_operations = b[i] - a[i];
        }
    }

    if (deficit_count > 1) {
        cout << "NO" << '\n';
        return;
    }

    if (deficit_count == 0) {
        cout << "YES" << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) {
            if (a[i] - b[i] < required_operations) {
                cout << "NO" << '\n';
                return;
            }
        }
    }

    cout << "YES" << '\n';
}

int main() {
    // Optimize standard I/O operations for competitive programming
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
