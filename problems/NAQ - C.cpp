#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
bool inBounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

const ll MOD = 998244353;

struct Block {
    ll a, b;
};

void solve() {
    int n;
    cin >> n;

    vector<Block> blocks(n);
    for (auto &[a, b] : blocks) {
        cin >> a >> b;
        if (a > b) swap(a, b);
    }

    sort(blocks.begin(), blocks.end(), [](Block x, Block y) {
        if (x.a != y.a) return x.a > y.a;
        return x.b > y.b;
    });

    for (int i = 1; i < n; i++) {
        if (blocks[i].b > blocks[i - 1].b) {
            cout << 0 << '\n';
            return;
        }
    }

    vector<ll> fact(n + 1, 1);
    for (int i = 1; i <= n; i++)
        fact[i] = fact[i - 1] * i % MOD;

    vector<Block> groups;
    vector<int> sizes;

    for (int i = 0; i < n;) {
        int j = i;
        while (j < n && blocks[j].a == blocks[i].a && blocks[j].b == blocks[i].b)
            j++;

        groups.push_back(blocks[i]);
        sizes.push_back(j - i);
        i = j;
    }

    auto positions = [&](ll W, ll H, ll w, ll h) -> ll {
        if (w > W || h > H) return 0;
        return (W - w + 1) % MOD * ((H - h + 1) % MOD) % MOD;
    };

    ll dp[2] = {fact[sizes[0]], 0};
    if (groups[0].a != groups[0].b)
        dp[1] = fact[sizes[0]];

    for (int i = 1; i < groups.size(); i++) {
        ll next[2] = {0, 0};

        for (int oldRot = 0; oldRot < 2; oldRot++) {
            if (dp[oldRot] == 0) continue;

            ll W = groups[i - 1].a;
            ll H = groups[i - 1].b;
            if (oldRot) swap(W, H);

            for (int newRot = 0; newRot < 2; newRot++) {
                ll w = groups[i].a;
                ll h = groups[i].b;

                if (newRot && w == h) continue;
                if (newRot) swap(w, h);

                ll ways = positions(W, H, w, h);
                ways = ways * dp[oldRot] % MOD;
                ways = ways * fact[sizes[i]] % MOD;

                next[newRot] = (next[newRot] + ways) % MOD;
            }
        }

        dp[0] = next[0];
        dp[1] = next[1];
    }

    cout << (dp[0] + dp[1]) % MOD << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
}