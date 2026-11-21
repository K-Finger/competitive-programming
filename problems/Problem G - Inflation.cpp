#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<ll> nums(n);
    iota(nums.rbegin(), nums.rend(), 1);

    vector<ll> c(n);
    for (size_t i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c.rbegin(), c.rend());
    double minF = std::numeric_limits<double>::max();
    for (size_t i = 0; i < n; i++) {
        if (c[i] > nums[i]) { // Canister exceeds balloon capacity
            cout << "impossible\n";
            return;
        }

        double f = (double)c[i] / nums[i];
        minF = min(minF, f);
    }
    cout << fixed << setprecision(10) << minF << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t = 1;
    while (t--) {
        solve();
    }
}
