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
    int n, d;
    cin >> n >> d;
    float x[n][d];

    REP(i, n)
    REP(j, d)
    cin >> x[i][j];

    int ans = 0;
    float dis;

    REP(i, n - 1)
    {
        FOR(j, i+1, n-1)
        {
            float tmp = 0;
            REP(k, d)
            {
                tmp += pow(x[i][k]-x[j][k], 2);
            }
            if (sqrt(tmp) == float(int(sqrt(tmp))))
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
