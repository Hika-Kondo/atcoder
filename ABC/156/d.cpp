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
#define NCK_MAX 510000
#define MOD 1e9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second

ll myPow(ll x, ll n, ll m){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

ll inv(int64_t a){
    return myPow(a, MOD-2, MOD);
}

ll ncr(int n, int r) {
  ll denominator = 1;
  ll molecule = 1;
  REP(i,r) {
    denominator *= (r-i) % MOD;
    molecule *= (n-i) % MOD;
  }
  return denominator * inv(molecule) % MOD;
}

int main(int argc, char const *argv[]) {
  // std::cout << "here" << '\n';
  ll n, a, b;
  ll ans;
  std::cin >> n >> a >> b;

  ans = (myPow(2,n,MOD)-1+MOD)%MOD;
  std::cout << ans << '\n';
  ans = (ans - ncr(n,a)+MOD)%MOD;
  std::cout << ans << '\n';
  ans = (ans - ncr(n,b)+MOD)%MOD;
  std::cout << ans << '\n';

  return 0;
}
