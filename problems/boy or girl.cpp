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
    string s;
    cin >> s;
    set<char> distinct(all(s));
    if (distinct.size() % 2 == 0) {
        cout << "CHAT WITH HER!\n";
    } else {
        cout << "IGNORE HIM!\n";
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
