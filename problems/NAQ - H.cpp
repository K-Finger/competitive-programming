#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool inBounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    for (int i = 0; i < 50; i++) {
        char guess = (rng() % 2) ? 'T' : 'F';
        cout << guess << endl;
        string correct;
        cin >> correct;

        if (correct == "-1")
            exit(0);

        char nextGuess;
        if (correct[0] == 'T')
            nextGuess = 'F';
        else
            nextGuess = 'T';

        cout << nextGuess << endl;
        cin >> correct;

        if (correct == "-1")
            exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}