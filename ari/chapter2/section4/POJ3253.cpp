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
    int n; std::cin >> n;
    std::vector<ll> l(n); RPE(i,n) std::cin >> l[i];
    int sum = 0; REP(i,n) sum+=l[i];
    sort(ALL(l));
    ll ans = 0;
    while(n > 1) {
        ll min1 = 0;min2 = 1;
        if (l[min1] < l[min2]) swap(min1,min2);
        REP(i,n) {
            if (l[i] < l[min1]) min1 = i;
            else if (l[i] < l[min2]) min2 = i;
        }
        ans += l[min1] + l[min2];
        l[min1] = l[min1] + l[min2];
        l[min2] = INF
        n--;
    }
    return 0;
}
