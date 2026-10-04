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
    int n;
    cin >> n;

    for (int r = 0; r < n; ++r) {
        string row = "";
        for (int c = 0; c < n; ++c) {
            if (r + c == n - 1) {
                row += 'C';
            } else {
                row += '.';
            }
        }
        cout << row << "\n";
    }
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