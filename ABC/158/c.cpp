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

float float_max(float a, float b) {
  return (a>b)?a:b;
}

float float_min(float a, float b) {
  return (a < b) ? a:b;
}

int main(int argc, char const *argv[]) {
  float a, b;
  ll _min, _max;
  float min_a, min_b, max_a, max_b;
  float max_, min_;
  std::cin >> a >> b;

  min_a = (25./2.) * float(a);
  max_a = (25./2.) * float(a + 1);

  min_b = 10. * float(b);
  max_b = 10. * float(b + 1);

  max_ = float_min(max_a, max_b);
  min_ = float_max(min_a, min_b);

  _min = int(min_ + 0.5);
  _max = int(max_);

  if (_min >= _max) {
    std::cout << "-1" << '\n';
  } else {
    std::cout << _min << '\n';
  }
  return 0;
}
