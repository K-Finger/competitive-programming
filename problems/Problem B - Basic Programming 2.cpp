#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
    int n, t;
    cin >> n >> t;

    vector<int> a(n);
    set<int> neededOne;
    set<int> s;
    map<int, int> freq;
    vector<int> rangeFive;

    for (size_t i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = x;
        neededOne.insert(7777 - x);
        s.insert(x);
        freq[x]++;

        if (x >= 100 && x <= 999) {
            rangeFive.push_back(x);
        }
    }

    if (t == 1) {
        bool found = false;

        for (int x : a) {
            if (x != 7777 - x && s.count(7777 - x)) {
                found = true;
                break;
            }
        }

        cout << (found ? "Yes" : "No");
    }

    if (t == 2) {
        if (a.size() == s.size()) {
            cout << "Unique";
        } else {
            cout << "Contains duplicate";
        }
    }

    if (t == 3) {
        int ans = -1;

        for (auto [x, cnt] : freq) {
            if (cnt > n / 2) {
                ans = x;
                break;
            }
        }

        cout << ans;
    }

    if (t == 4) {
        sort(a.begin(), a.end());

        if (n % 2 == 1) {
            cout << a[n / 2];
        } else {
            cout << a[n / 2 - 1] << " " << a[n / 2];
        }
    }

    if (t == 5) {
        sort(rangeFive.begin(), rangeFive.end());

        for (size_t i = 0; i < rangeFive.size(); i++) {
            if (i > 0) cout << " ";
            cout << rangeFive[i];
        }
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }
}
