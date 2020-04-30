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

vector<ll> a;


int main(int argc, char const *argv[]) {
    int n,m; std::cin >> n >> m;
    std::priority_queue<ll> a; REP(i,n) {
        ll temp; std::cin >> temp;
        a.push(temp);
    }

    REP(i,m) {
        ll temp = a.top(); a.pop();
        a.push(temp/2);
    }
    ll ans = 0; REP(i,n) {
        ans += a.top(); a.pop();
    }
    cout << ans << '\n';
    return 0;
}
