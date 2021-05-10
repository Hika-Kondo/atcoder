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
    int n,m;
    cin >> n >> m;
    priority_queue<pair<ll,ll>> que;
    REP(i,n)
    {
        ll a; 
        cin >> a;
        que.push(make_pair(a,1));
    }
    
    REP(i,m)
    {
        ll b,c;
        cin >> b >> c;
        que.push(make_pair(c,b));
    }

    ll ans = 0;
    REP(i,n)
    {
        auto p = que.top();
        que.pop();
        if (p.S != 1)
            que.push(make_pair(p.F,p.S-1));
        ans += p.F;
    }

    cout << ans << endl;
    return 0;
}
