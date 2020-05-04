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
    ll n,m; std::cin >> n >> m;
    std::vector<ll> h(n);
    std::map<int, std::set<int>> path;
    REP(i,n)std::cin >> h[i];
    REP(i,m) {
        int a, b; std::cin >> a >> b;
        path[a-1].insert(b-1);
        path[b-1].insert(a-1);
    }

    ll ans = 0;

    REP(i,n) {
        bool flag = true;
        for (auto temp : path[i]) {
            ll now_height = h[i];
            ll comp_height = h[temp];
            if (now_height <= comp_height) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ans++;
        }
    }
    std::cout << ans << "\n";
    return 0;
}
