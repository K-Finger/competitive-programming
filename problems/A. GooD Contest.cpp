#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

void solve() {
    ll a, b, c;
    cin >> a >> b >> c;
    
    ll dif = b - a; // 3
    
    
    // ALICE HAS LESS
    if (dif > 0) {
    	if (abs((a + c) - b) > dif) {
    		cout << abs((a + c) - b) << '\n';
    	} else {
    		cout << dif << '\n';
    	}
    } else {
    	// ALICE HAS MORE, TAKE ALL
    	cout << abs((a + c) - b) << '\n';
    }
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
