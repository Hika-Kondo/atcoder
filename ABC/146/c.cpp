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

int keta(ll center) {
  int k = 0;
  while ((center/10)!=0) {
    k++;
    center/=10;
  }
  k++;
  return k;
}

ll price(ll a,ll  b, ll center) {
  int k = keta(center);
  return a * center + b * k;
}

void solove(ll a, ll b, ll x) {

  ll left = 0, right=ll(1e9)+1;
  ll center;
  while (left+1 < right) {
    center = (left+right)/2;
    ll p = price(a, b, center);
    if (p <= x) left = center;
    else right = center;
    // std::cout << "price " << p << "\ta " << a << "\tb " << b << "\tcenter " << center << '\n';
  }
  std::cout << left << '\n';
}

int main(int argc, char const *argv[]) {
  ll a,b;
  ll x;
  std::cin >> a >> b >> x;
  if (price(a,b,1) > x) {
    std::cout << 0 << '\n';
    return 0;
  }
  solove(a, b, x);
  return 0;
}
