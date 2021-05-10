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

int main(int argc, char const *argv[]) {
    int n,m;
    cin >> n >> m;
    vector<ll> a(n);
    vector<tuple<ll,int>> itm;
    REP(i,n)
        cin >> a[i];
    REP(i,m)
    {   
        int b;
        ll c;
        cin >> b >> c;
        itm.emplace_back(c,b);
    }

    sort(ALL(a));
    sort(ALL(itm),greater<tuple<ll,int>>());

    ll vec_idx = 0;
    REP(i,SIZE(itm))
    {
        // cが新しい数字, bが変更できる数
        ll c;
        int b;
        tie(c,b) = itm[i];
        REP(j,b)
        {
            if (a[vec_idx] < c)
            {
                a[vec_idx] = c;
                vec_idx++;
            } 
            else
                break;
        }
    }

    ll ans = 0;
    REP(i,n)
        ans += a[i];
    cout << ans << endl;
    return 0;
}
