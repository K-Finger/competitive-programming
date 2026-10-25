#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int longestZeros = 0;
    int runningZeros = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            runningZeros++;
        } else {
            longestZeros = max(longestZeros, runningZeros);
            runningZeros = 0;
        }
        if (i == n - 1 && s[i] == '0') {
            int j = 0;
            while (j < n && s[j] == '0') {
                runningZeros++;
                j++;
            }
        }
    }
    longestZeros = max(longestZeros, runningZeros); 

    cout << longestZeros << '\n';
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
