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
    ll n,k; cin >> n >> k;
    int dp[n][61] = {{-1}},a[n];
    REP(i,n)
        cin >> a[i];


    REP(i,n)
        dp[a[i]-1][0] = i;

    int log2 = log(k) / log(2);

    FOR(j,1,60)
    {   
        REP(i,n)
            if (dp[i][j-1] != -1)
                dp[i][j] = dp[dp[i][j-1]][j-1];
    }

    int ans[n];
    REP(i,n)
        ans[i] = i;
    REP(i, log2+1)
    {
        if (k & (ll(1 << i)))
        {   
            int tmp[n];
            REP(j,n)
                tmp[j] = ans[dp[j][i]];
            REP(j,n)
                ans[j] = tmp[j];
        }
    }
    REP(i,n)
        cout << ans[i] << " ";
    cout << endl;
    REP(i,n)
    {
        if (ans[i] == 0)
            cout << i+1 << endl;
    }
    
    return 0;
}
