#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;

    int MOD = 1e9 + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= 6; i++) {
            if (j - i >= 0) {
                dp[j] = (dp[j] + dp[j - i]) % MOD;
            }
        }
    }

    cout << dp[n] << '\n';
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
