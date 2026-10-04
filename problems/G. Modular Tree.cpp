
#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    vector<ll> num(3);
    cin >> num[0] >> num[1] >> num[2];
    
    sort(num.begin(), num.end());
    
    ll initial_range = num[2] - num[0];
    ll reduced_range = num[1];
    
    cout << min(initial_range, reduced_range) << "\n";
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