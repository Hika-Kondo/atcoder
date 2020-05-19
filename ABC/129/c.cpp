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
#define MOD (ll)1e9+7      //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main(int argc, char const *argv[])
{
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    ll dp[2][n+2];
    dp[0][0] = 1;
    dp[1][0] = 0;
    dp[0][1] = 1;
    dp[1][1] = 0;
    REP(i,m)
    {
        cin >> a[i];
        dp[0][a[i]] = INF * -1;
        dp[1][a[i]] = INF * -1;
    }
    

    FOR(i,2,n)
    {   
        if (dp[0][i] == INF * -1) continue;
        dp[0][i] = (max(dp[0][i-1],(ll)0) + max(dp[1][i-1],(ll)0));
        dp[1][i] = (max(dp[0][i-2],(ll)0) + max(dp[1][i-2],(ll)0));
        dp[0][i] %= MOD;
        dp[1][i] %= MOD;
        
    }

    ll ans = dp[0][n] + dp[1][n];
    ans %= MOD;
    cout << ans << endl;
    return 0;
}
