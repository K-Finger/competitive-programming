#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        int highest = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x >= highest) {
                highest = x;
            } else {
                ans++;
            }
        }

        cout << ans << '\n';
    }
}
