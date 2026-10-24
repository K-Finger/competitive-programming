#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Point {
    ll x, y;
};

ll crossProduct(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y)
         - (b.y - a.y) * (c.x - a.x);
}

class LowerHull {
public:
    // Is p above or on this lower hull?
    bool contains(Point p) {
        if (hull.empty())
            return false;

        if (p.x < hull.begin()->first ||
            p.x > hull.rbegin()->first)
            return false;

        auto right = hull.lower_bound(p.x);

        if (right != hull.end() && right->first == p.x) {
            return p.y >= right->second;
        }

        if (right == hull.begin() || right == hull.end())
            return false;

        auto left = prev(right);

        Point a = {left->first, left->second};
        Point b = {right->first, right->second};

        return crossProduct(a, b, p) >= 0;
    }

    void addNode(Point p) {
        auto same = hull.find(p.x);

        if (same != hull.end()) {
            if (same->second <= p.y)
                return;

            hull.erase(same);
        } else {
            if (hull.size() >= 2 &&
                p.x > hull.begin()->first &&
                p.x < hull.rbegin()->first &&
                contains(p)) {
                return;
            }
        }

        auto it = hull.insert({p.x, p.y}).first;

        /*
         * Remove bad points to the left.
         *
         * For a lower hull, consecutive points must make
         * a counter-clockwise turn:
         *
         * cross(a, b, c) > 0
         */
        while (it != hull.begin()) {
            auto b = prev(it);

            if (b == hull.begin())
                break;

            auto a = prev(b);

            Point pa = {a->first, a->second};
            Point pb = {b->first, b->second};
            Point pc = {it->first, it->second};

            if (crossProduct(pa, pb, pc) > 0)
                break;

            hull.erase(b);
        }

        // Remove bad points to the right.
        while (true) {
            auto b = next(it);

            if (b == hull.end())
                break;

            auto c = next(b);

            if (c == hull.end())
                break;

            Point pa = {it->first, it->second};
            Point pb = {b->first, b->second};
            Point pc = {c->first, c->second};

            if (crossProduct(pa, pb, pc) > 0)
                break;

            hull.erase(b);
        }
    }

private:
    map<ll, ll> hull;
};

class ConvexHull {
public:
    void addNode(ll x, ll y) {
        lower.addNode({x, y});

        // Flip across x-axis.
        // Original upper hull becomes a lower hull.
        upper.addNode({x, -y});
    }

    bool query(ll x, ll y) {
        return lower.contains({x, y}) &&
               upper.contains({x, -y});
    }

private:
    LowerHull lower;
    LowerHull upper;
};

void solve() {
    int q;
    cin >> q;

    ConvexHull hull;

    for (int i = 0; i < q; i++) {
        int t;
        ll x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            hull.addNode(x, y);
        } else {
            cout << (hull.query(x, y) ? "YES" : "NO") << '\n';
        }
    }
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
