#include<bits/stdc++.h>

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

std::vector<std::vector<P>> tree; // treeのインデックスが節の番号 itemのP.F 子供のインデックス,　P.S　辺の番号
std::vector<int> ans;

void dfs(int parent, int now, int color) {
  int children_size = SIZE(tree[now]);
  int c = 1;
  REP(i,children_size) {
    if (tree[now][i].F == parent) continue;
    if (c == color) c++;
    ans[tree[now][i].S] = c;
    // std::cout << "parent " << parent+1 <<"\tnow " << now+1 << "\tchildren " << tree[now][i].F+1 << "\tcolor " << c <<  '\n';
    dfs(now,tree[now][i].F,c);
    c++;
  }
}

int main(int argc, char const *argv[]) {
  int n; std::cin >> n;
  tree.resize(n);
  ans.resize(n-1);
  REP(i,n-1) {
    int a,b; std::cin >> a >> b;
    a--; b--;
    tree[a].PB((P){b,i});
    tree[b].PB((P){a,i});
  }
  dfs(-1,0,-1);
  std::cout << MAX(ans) << '\n';
  REP(i,n-1) std::cout << ans[i] << '\n';

  return 0;
}
