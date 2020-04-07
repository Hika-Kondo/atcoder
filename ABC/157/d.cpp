//参考：http://ehafib.hatenablog.com/entry/2015/12/23/164517
//インクルード
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define MOD 10000007
#define PB push_back
#define MP make_pair
#define F first
#define S second


struct UnionFind {
  // 根はそのUnionの大きさの絶対値で負の値を持つ.
  // 葉はそれぞれ根のインデックスを持つ.
  std::vector<int> d;
  UnionFind(int n): d(n, -1) {}
  // 根を探す
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    // xとyを合体させる
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) {return -d[find(x)];}
};

int main(int argc, char const *argv[]) {
  //　入力
  // s
  // q
  // query=(1, 2) if query == 2 top_or_bottom str
  int deg[INF];
  std::vector<int> to[INF];
  int n, m, k;
  std::cin >> n >> m >> k;

  UnionFind uf(n);

  REP(i,m) {
    int a, b;
    std::cin >> a >> b;
    deg[a]++;
    deg[b]++;
    uf.unite(a,b);
  }
  REP(i,k) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  REP(i,n) {
    int ans = uf.size(i) - 1 - deg[i];
    for (int u : to[i]) {
      if (uf.same(i,u)) --ans;
    }
    printf("%d%c", ans, i==n-1?'\n':' ');
  }
  return 0;
}
