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
typedef pair<int,int> P;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define NCK_MAX 510000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second


int progress_x[4] = {0,1,0,-1};
int progress_y[4] = {1,0,-1,0}

int solove(P start, P goal, std::string meiro[h][w]) {
  int distance[h][w]={{-1}};
  start_x=start.F;
  start_y=start.S;
  goal_x = goal.F;
  goal_y = goal.S;
  if (meiro[start_x][start_y] == "#" || meiro[goal_x][goal_y] == "#") {
    return -1;
  }
  queue<P> que;
  distance[start_x][start_y] = 0;
  que.push(P(start_x,start_y));
  while (que.size()) {
    P p = que.front(); que.pop();
    REP(i,4) {
      int nx,ny;
      nx = p.F + progress_x[i];
      ny = p.S + progress_y[i];
      if (nx >=0 && nx < h && ny >= 0 && ny < w && meiro[nx][ny] != "#" && distance[nx][ny] == -1) {
        que.push(P(nx,ny));
        distance[nx][ny] = d[p.F][p.S]+1;
      }
    }
  }
  return distance[goal_x][goal_y];
}

int h,w;
int main(int argc, char const *argv[]) {
  int max_path = 0;
  std::cin >> h >> w;
  std::string meiro[h][w];
  REP(i,h) {
    REP(j,w) {
      std::cin >> meiro[i][j];
    }
  }

  REP(start_x,h) {
    REP(start_y,w) {
      REP(goal_x,h) {
        REP(goal_y,w) {
          P start(start_x,start_y);
          P goal(goal_x, goal_y);
          if (start == goal) {
            continue;
          }
          int temp;
          temp = solove(start, goal,meiro);
          if (temp > max) {
            max = temp;
          }
        }
      }
    }
  }

  return 0;
}
