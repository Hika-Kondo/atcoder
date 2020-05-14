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
#define MOD ll(1e9+7)     //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second



int n;
ll dp[100005][13];



int main(int argc, char const *argv[])
{

    string s;
    cin >> s;
    n = SIZE(s);
    dp[0][0] = 1 ;
    REP(i,n) 
    {
        int tmp;
        if (s[i] == '?')
            tmp = -1;
        else
            tmp = s[i] - '0';

        REP(j,10)
        {
            if (tmp != -1 && tmp != j) 
                continue;

            REP(k,13) 
            {
                dp[i+1][(10*k+j)%13] += dp[i][k];
            }

            REP(k,13) dp[i+1][k] %= MOD;
        }
    }
    cout << dp[n][5] << "\n";

    return 0;
}
