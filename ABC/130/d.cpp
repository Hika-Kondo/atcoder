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
    ll n,k;
    cin >> n >> k;

    vector<ll> sum(n);
    sum[0] = 0;
    cin >> sum[0];
    REP(i,n-1)
    {
        ll tmp;
        cin >> tmp;
        sum[i+1] = sum[i] + tmp;
    }

    ll tot = 0;

    REP(i,n)
    {
        ll now = sum[i];
        ll sa = now - k;

        auto low = upper_bound(sum.begin(),sum.end(),sa);
        ll idx = low - sum.begin();
        if (idx == 0 && sum[i] >= k)
            tot++;
        else if (idx != 0 && sum[i] - sum[idx-1] >= k)
            tot+= idx + 1;
        else if (sum[i] >= k && idx != 0)
            tot += idx;
    }
    cout << tot << endl;
    return 0;
}
