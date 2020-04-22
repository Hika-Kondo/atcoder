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
#define NCK_MAX 510000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

ll lcm(ll a, ll b) { return a * b / __gcd(a, b); }

int main(int argc, char const *argv[]) {
  ll n,m; std::cin >> n >> m;
  std::vector<ll> a(n,0); REP(i,n) std::cin >> a[i];
  ll _gcd, LeastCommonMultipule=1;
  // init
  REP(i,n) LeastCommonMultipule=lcm(LeastCommonMultipule,a[i]);

  // if (m < LeastCommonMultipule/2) {
  //   std::cout << 0 << '\n';
  //   return 0;
  // }
  for (int i = 0; i < n; i++) {
    if ((LeastCommonMultipule / a[i]) % 2 == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  ll ans;
  ans = m/LeastCommonMultipule;
  ll sa = m - ans*LeastCommonMultipule;
  if (sa < LeastCommonMultipule/2) std::cout << ans << '\n';
  else std::cout << ans+1 << '\n';
  return 0;
}
