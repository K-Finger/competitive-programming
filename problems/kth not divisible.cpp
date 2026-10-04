#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool inBounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve() {
    ll n, k;
    cin >> n >> k;
    // every n numbers, n-1 are not divisible by n
    // so we need to find how many "groups" of n we need
    ll groups = (k - 1) / (n - 1);
    ll rem = k - groups * (n - 1);
    ll ans = groups * n + rem;
    if (ans % n == 0) ans++;
    cout << ans << "\n";
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
