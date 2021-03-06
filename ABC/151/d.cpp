cd //参考：http://ehafib.hatenablog.com/entry/2015/12/23/164517
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
typedef pair<int,int> P;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1001001001
#define NCK_MAX 510000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

int move_x[] = {1,0,-1,0}, move_y[]={0,1,0,-1};

int main(int argc, char const *argv[]) {
  int h,w;
  std::cin >> h >> w;
  std::string s[h];
  int ans = 0;
  REP(i,h) std::cin >> s[i];
  REP(sx,h) REP(sy,w) {
    vector<vector<int>> d(h, vector<int>(w, INF));
    if (s[sx][sy] == '#') continue;
    d[sx][sy] = 0;
    queue<P> que;
    que.push(P(sx,sy));
    auto update = [&](int i, int j, int x){
      if (d[i][j] != INF || s[i][j] == '#') return;
      d[i][j] = x;
      que.push(P(i,j));
    };
    while (que.size()!=0) {
      int now_x = que.front().F,now_y=que.front().S;
      que.pop();
      // std::cout << "here" << '\n';
      REP(idx,4) {
        int dx=move_x[idx],dy=move_y[idx];
        int new_x=now_x+dx,new_y=now_y+dy;
        if (new_x < 0 || new_x >=h || new_y < 0 || new_y >= w) continue;
        update(new_x,new_y,d[now_x][now_y]+1);
      }
    }
    REP(idx_x,h) REP(idx_y,w) {
      if (ans < d[idx_x][idx_y] && d[idx_x][idx_y] !=INF) ans = d[idx_x][idx_y];
    }
  }
  std::cout << ans << '\n';

  return 0;
}
