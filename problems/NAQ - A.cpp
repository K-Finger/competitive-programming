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
    
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
    	int x;
    	cin >> x;
    	if (x <= 10) {
    		seen.insert(1);
    	} else if (x <= 20) {
    		seen.insert(2);
    	} else if (x <= 30) {
    		seen.insert(3);
    	} else if (x <= 40) {
    		seen.insert(4);
    	}
    }
    
    cout << seen.size() << '\n';
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