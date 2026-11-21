#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> exams(n);
    for (int i = 0; i < n; i++) {
        cin >> exams[i].first >> exams[i].second;
    }

    sort(exams.begin(), exams.end());

    int ans = 0;

    for (auto [a, b] : exams) {
        ans = min(a >= ans ? a : INT_MAX, b >= ans ? b : INT_MAX);
    }

    cout << ans << '\n';
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
