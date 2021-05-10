#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;
struct mint
{
    ll x; // typedef long long ll;
    mint(ll x = 0) : x((x % mod + mod) % mod) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a)
    {
        if ((x += a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator-=(const mint a)
    {
        if ((x += mod - a.x) >= mod)
            x -= mod;
        return *this;
    }
    mint &operator*=(const mint a)
    {
        (x *= a.x) %= mod;
        return *this;
    }
    mint operator+(const mint a) const { return mint(*this) += a; }
    mint operator-(const mint a) const { return mint(*this) -= a; }
    mint operator*(const mint a) const { return mint(*this) *= a; }
    mint pow(ll t) const
    {
        if (!t)
            return 1;
        mint a = pow(t >> 1);
        a *= a;
        if (t & 1)
            a *= *this;
        return a;
    }

    // for prime mod
    mint inv() const { return pow(mod - 2); }
    mint &operator/=(const mint a) { return *this *= a.inv(); }
    mint operator/(const mint a) const { return mint(*this) /= a; }
};
istream &operator>>(istream &is, const mint &a) { return is >> a.x; }
ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

int main()
{
    int n;
    cin >> n;
    int zero = 0;
    map<pair<ll, ll>, P> mp;
    rep(i, n)
    {
        ll x, y;
        cin >> x >> y;
        if (x == 0 && y == 0)
        {
            zero++;
            continue;
        }
        ll g = gcd(x, y);
        x /= g;
        y /= g;
        if (y < 0)
            x = -x, y = -y;
        if (y == 0 && x < 0)
            x = -x, y = -y;
        bool rot90 = (x <= 0);
        if (rot90)
        {
            ll tmp = x;
            x = y;
            y = -tmp;
        }
        if (rot90)
            mp[{x, y}].first++;
        else
            mp[{x, y}].second++;
    }

    mint ans = 1;
    for (auto p : mp)
    {
        int s = p.second.first;
        int t = p.second.second;
        mint now = 1;
        now += mint(2).pow(s) - 1;
        now += mint(2).pow(t) - 1;
        ans *= now;
    }
    ans -= 1;

    ans += zero;
    cout << ans << endl;
    return 0;
}
