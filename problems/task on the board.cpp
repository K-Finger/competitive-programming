#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) {
        string s;
        int m;
        cin >> s >> m;
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        // count frequency of each char
        vector<int> freq(26);
        for (char c : s) freq[c - 'a']++;

        string ans(m, '?');
        vector<bool> done(m, false);

        // process in layers - zeros first (largest chars), then sum=1, etc.
        while (true) {
            vector<int> zeros;
            for (int i = 0; i < m; i++) {
                if (!done[i] && b[i] == 0) zeros.push_back(i);
            }
            if (zeros.empty()) break;

            // find largest available char with enough count
            char c = '?';
            for (int ch = 25; ch >= 0; ch--) {
                if (freq[ch] >= (int)zeros.size()) {
                    c = 'a' + ch;
                    freq[ch] -= zeros.size();
                    break;
                }
            }

            for (int i : zeros) {
                ans[i] = c;
                done[i] = true;
            }

            // decrease b values for remaining positions
            for (int i = 0; i < m; i++) {
                if (!done[i]) {
                    for (int j : zeros) {
                        if (i != j) b[i]--;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
}
