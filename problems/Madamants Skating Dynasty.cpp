#include <iostream>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    
    int least = min({a1, a2, a3});
    cout << (n - least) << '\n';
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
