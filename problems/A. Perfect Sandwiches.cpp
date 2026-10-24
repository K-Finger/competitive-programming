#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    
    int k = min({a / 2, b, a - b});
    
    if (k > 0) {
        cout << k << "\n";
    } else {
        cout << -1 << "\n";
    }
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
