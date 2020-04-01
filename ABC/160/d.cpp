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
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second
// #MAXR 100000 //10^5:最大のrange(素数列挙などで使用)

int main(int argc, char const *argv[]) {
  ll n, x, y,counter = 0;
  int temp, shortcut, not_shortcut;
  int ans[pow(10,3) * 3];
  int ans_counter[3* pow(10,3)];
  std::cin >> n >> x >> y;

  REP(i, n-1){
    FOR(j, i+1, n) {
      if (j < x) {
        temp = j-i;
        ans[counter] = temp;
      } else {
        shortcut = abs((x-1) - i) + 1 + abs((y-1)-j);
        not_shortcut = j-i;
        temp = min(shortcut,not_shortcut);
        ans[counter] = temp;
      }
      counter ++;
    }
  }

  REP(i,n) {
    ans_counter[i] = 0;
    REP(j,sizeof(ans)) {
      if (ans[j] == i+1) {
        ans_counter[i] ++;
      }
    }
  }
  REP(i,n) std::cout << ans_counter[i] << '\n';
  return 0;
}
