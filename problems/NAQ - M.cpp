#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;
using Point = pair<ll, ll>;

#define all(x) (x).begin(), (x).end()

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

bool inBounds(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

i128 distSq(Point a, Point b) {
    i128 x = (i128)a.first - b.first;
    i128 y = (i128)a.second - b.second;
    return x * x + y * y;
}

i128 cross(Point a, Point b, Point c) {
    i128 x1 = (i128)b.first - a.first;
    i128 y1 = (i128)b.second - a.second;
    i128 x2 = (i128)c.first - a.first;
    i128 y2 = (i128)c.second - a.second;
    return x1 * y2 - y1 * x2;
}

bool adjacent(int a, int b, int n) {
    return abs(a - b) == 1 || abs(a - b) == n - 1;
}

void solve() {
    int n;
    ll k;
    cin >> n >> k;

    vector<Point> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    if (k == 0) {
        cout << 0 << "\n";
        return;
    }

    i128 maxSqDist = 0;
    int j = 1;

    for (int i = 0; i < n; i++) {
        int nextI = (i + 1) % n;

        while (cross(pts[i], pts[nextI], pts[(j + 1) % n]) >
               cross(pts[i], pts[nextI], pts[j])) {
            j = (j + 1) % n;
        }

        maxSqDist = max(maxSqDist, distSq(pts[i], pts[j]));
        maxSqDist = max(maxSqDist, distSq(pts[nextI], pts[j]));

        int nextJ = (j + 1) % n;

        if (cross(pts[i], pts[nextI], pts[nextJ]) ==
            cross(pts[i], pts[nextI], pts[j])) {
            maxSqDist = max(maxSqDist, distSq(pts[i], pts[nextJ]));
            maxSqDist = max(maxSqDist, distSq(pts[nextI], pts[nextJ]));
        }
    }

    long double diameter = sqrt((long double)maxSqDist);
    ll ans = ceil((long double)k / (2.0L * diameter));

    i128 target = (i128)k * k;

    auto enough = [&](ll cuts) {
        return (i128)4 * cuts * cuts * maxSqDist >= target;
    };

    while (ans > 1 && enough(ans - 1))
        ans--;

    while (!enough(ans))
        ans++;

    i128 possible = (i128)4 * ans * ans * maxSqDist;

    if (possible == target) {
        set<pair<int, int>> diameterCuts;
        j = 1;

        for (int i = 0; i < n; i++) {
            int nextI = (i + 1) % n;

            while (cross(pts[i], pts[nextI], pts[(j + 1) % n]) >
                   cross(pts[i], pts[nextI], pts[j])) {
                j = (j + 1) % n;
            }

            int nextJ = (j + 1) % n;

            vector<pair<int, int>> pairs = {
                {i, j},
                {nextI, j}
            };

            if (cross(pts[i], pts[nextI], pts[nextJ]) ==
                cross(pts[i], pts[nextI], pts[j])) {
                pairs.push_back({i, nextJ});
                pairs.push_back({nextI, nextJ});
            }

            for (auto [a, b] : pairs) {
                if (a == b)
                    continue;

                if (distSq(pts[a], pts[b]) != maxSqDist)
                    continue;

                if (adjacent(a, b, n))
                    continue;

                if (a > b)
                    swap(a, b);

                diameterCuts.insert({a, b});
            }
        }

        if ((ll)diameterCuts.size() < ans)
            ans++;
    }

    cout << ans << "\n";
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