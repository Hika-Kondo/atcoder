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
    int n;
    cin >> n;
    int p[n];
    REP(i,n)
        cin >> p[i];

    int ans = 0;

    FOR(i,1,n-2)
    {
        int maxitm = max({p[i-1],p[i],p[i+1]});
        int minitm = min({p[i-1],p[i],p[i+1]});
        if (p[i] != maxitm && p[i] != minitm)
        {
            ans++;        
        }
    }
    cout << ans << endl;
    return 0;   
}
