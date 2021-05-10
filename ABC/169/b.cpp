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
    ll n;
    cin >> n;
    ll a[n];
    ll ans = 1;
    REP(i,n)
    {
        cin >> a[i];
        if (a[i] == 0)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    REP(i,n)
    {   
        cout << double(1000000000000000001 / ans);
        if (double(1000000000000000001 / ans) >= float(a[i]))
        {
            cout << -1 << endl;
            return 0;
        }
            ans *= a[i];
        
    }
    
    cout << ans << endl;
    return 0;   
}
