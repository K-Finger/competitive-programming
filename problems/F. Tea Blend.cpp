#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct Hash {
    ull x, y;

    bool operator==(const Hash& other) const {
        return x == other.x && y == other.y;
    }
};

struct HashFunc {
    size_t operator()(const Hash& h) const {
        return h.x ^ (h.y + 0x9e3779b97f4a7c15ULL + (h.x << 6) + (h.x >> 2));
    }
};

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    const int MAXA = 1000000;

    static vector<int> spf(MAXA + 1);
    static vector<ull> h1(MAXA + 1), h2(MAXA + 1);
    static bool initialized = false;

    if (!initialized) {
        for (int i = 0; i <= MAXA; i++)
            spf[i] = i;

        for (int i = 2; i * i <= MAXA; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= MAXA; j += i) {
                    if (spf[j] == j)
                        spf[j] = i;
                }
            }
        }

        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

        for (int i = 2; i <= MAXA; i++) {
            if (spf[i] == i) {
                h1[i] = rng();
                h2[i] = rng();
            }
        }

        initialized = true;
    }

    vector<Hash> sig(n);

    for (int i = 0; i < n; i++) {
        int x = a[i];
        ull x1 = 0, x2 = 0;

        while (x > 1) {
            int p = spf[x];
            int cnt = 0;

            while (x % p == 0) {
                x /= p;
                cnt++;
            }

            if (cnt % 2) {
                x1 ^= h1[p];
                x2 ^= h2[p];
            }
        }

        sig[i] = {x1, x2};
    }

    unordered_map<Hash, ll, HashFunc> freqA;
    unordered_map<Hash, ll, HashFunc> freqPrefix;

    for (int i = 0; i < n; i++) {
        freqA[sig[i]]++;
    }

    Hash curr = {0, 0};

    for (int j = 0; j < n; j++) {
        curr.x ^= sig[j].x;
        curr.y ^= sig[j].y;

        freqPrefix[curr]++;
    }

    ll ans = 0;

    for (auto &[state, cnt] : freqA) {
        ans += cnt * freqPrefix[state];
    }

    cout << ans << '\n';
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
