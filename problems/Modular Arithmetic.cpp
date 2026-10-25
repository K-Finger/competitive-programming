#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128_t;

ll extended_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extended_gcd(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll g = extended_gcd(a, m, x, y);

    if (g != 1) {
        return -1;
    }

    return (x % m + m) % m;
}

void solve(ll n, ll t) {
    while (t--) {
        ll x, y;
        char op;
        cin >> x >> op >> y;

        x = (x % n + n) % n;
        y = (y % n + n) % n;

        if (op == '+') {
            cout << (x + y) % n << '\n';
        }
        else if (op == '-') {
            cout << (x - y + n) % n << '\n';
        }
        else if (op == '*') {
            cout << (ll)((i128)x * y % n) << '\n';
        }
        else if (op == '/') {
            ll inverse = mod_inverse(y, n);

            if (inverse == -1) {
                cout << -1 << '\n';
            }
            else {
                cout << (ll)((i128)x * inverse % n) << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;

    while (cin >> n >> t) {
        if (n == 0 && t == 0) {
            break;
        }

        solve(n, t);
    }
}
