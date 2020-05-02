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

std::vector<int> tree;
std::vector<int> a,b,c,d;
int n,m,q;
ll ans = 0;

void dfs(int now) {
    if (now == n-1) {
        FOR(j,1,m) {
            if (tree[now-1] > j) continue;
            ll temp = 0;
            tree[now] = j;
            REP(i,q) {
                if ( tree[b[i]-1] - tree[a[i]-1] == c[i]) {
                    temp += d[i];
                }
            }
            if (temp > ans) ans = temp;
        }
    } else {
        FOR(i,1,m) {
            if (tree[now-1] > i) continue;
            tree[now] = i;
            dfs(now+1);
        }
    }
}

int main(int argc, char const *argv[]) {
    std::cin >> n >> m >> q;
    tree.resize(n);
    a.resize(q); b.resize(q); c.resize(q); d.resize(q);
    REP(i,q) std::cin >> a[i] >> b[i] >> c[i] >> d[i];
    dfs(0);
    std::cout << ans << "\n";
    return 0;
}
