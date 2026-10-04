#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool inBounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

const ll MOD = 998244353;

void solve() {
    string n;
    cin >> n;

    ll val = 0;
    for (char c : n) {
        val = (val * 10 + (c - '0')) % MOD;
    }

    ll a = val;
    ll b = (val + 1) % MOD;
    ll c = (val + 2) % MOD;

    ll ans = a * b % MOD;
    ans = ans * c % MOD;
    ans = ans * 166374059 % MOD;

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}