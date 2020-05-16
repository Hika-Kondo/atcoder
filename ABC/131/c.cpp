#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second

ll counter(ll a, ll b, ll q)
{
    ll a_q, b_q;
    if (a % q == 0)
        a_q = a / q;
    else
        a_q = a / q + 1;
    b_q = b / q;

    return (b_q - a_q + 1);

}

int main(int argc, char const *argv[]) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    
    ll _c = counter(a, b, c);
    ll _d = counter(a, b, d);
    ll cd = counter(a, b, c/__gcd(c,d) * d);

    ll ans = (b - a + 1) - _c - _d + cd;

    cout << ans << endl;

    return 0;
}
