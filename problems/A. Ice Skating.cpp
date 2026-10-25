#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.assign(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);

        if (rootA == rootB) return;

        if (sz[rootA] < sz[rootB]) swap(rootA, rootB);

        parent[rootB] = rootA;
        sz[rootA] += sz[rootB];
    }
};

void solve() {
    int n;
    cin >> n;
    DSU dsu(n);

    unordered_map<int, int> seenX, seenY;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        if (seenX.contains(x)) {
            dsu.unite(i, seenX[x]);
        } else {
            seenX[x] = i;
        }

        if (seenY.contains(y)) {
            dsu.unite(i, seenY[y]);
        } else {
            seenY[y] = i;
        }
    }

    int components = 0;

    for (int i = 0; i < n; i++) {
        if (dsu.find(i) == i) {
            components++;
        }
    }

    cout << components - 1 << '\n';
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
