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

int main(int argc, char const *argv[]) {
  //　入力
  // s
  // q
  // query=(1, 2) if query == 2 top_or_bottom str

  std::string first;
  ll q;
  int query, top_or_bottom;
  std::string s, ans, temp;
  bool is_reverse = false;
  std::vector<std::string> top, bottom;

  std::cin >> first;
  std::cin >> q;

  REP(i,q) {
    std::cin >> query;
    if (query == 1) is_reverse = (is_reverse)?false:true;
    else {
      std::cin >> top_or_bottom >> s;
      if (top_or_bottom == 1) {
        if (!is_reverse) top.PB(s);
        else bottom.PB(s);
      } else {
        if (!is_reverse) bottom.PB(s);
        else top.PB(s);
      }
    }
  }
  REPD(i,top.size()) temp += top[i];
  temp += first;
  REP(i,bottom.size()) temp += bottom[i];

  if (is_reverse) REPD(i, (int)(temp.length())) ans += temp[i];
  else REP(i,(int)(temp.length())) ans += temp[i];
  std::cout << ans << '\n';
  return 0;
}
