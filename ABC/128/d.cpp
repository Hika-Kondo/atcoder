#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

//マクロ
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())      //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000 //10^12
#define MOD 10000007      //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d%d", &N, &K);
    ll v[N];
    REP(i, N)
    {
        scanf("%lld", &v[i]);
    }

    ll ans = 0;
    // 左からn個, 右からm個, 戻すのはl個
    REP(n, K + 1) REP(m, K - n + 1) REP(l, K - n - m + 1)
    {
        if (n + m > N) continue;
        if (n + m < l) continue;
        vector<ll> itm;
        REP(i,n)
            itm.PB(v[i]);
        REP(i,m)
            itm.PB(v[N-1-i]);
        sort(ALL(itm));
        ll sum = accumulate(ALL(itm),0);
        ll minus = 0;
        REP(i,l)
            minus -= itm[i];
        sum += minus;
        if (ans < sum)
            ans = sum;
    }

    printf("%lld\n", ans);
    return 0;
}
