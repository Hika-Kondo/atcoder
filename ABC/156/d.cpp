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
#define MOD 1000000007
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


ll fac[NCK_MAX], finv[NCK_MAX], inv[NCK_MAX], facn[NCK_MAX];

// テーブルを作る前処理
void COMinit(ll n) {
    fac[0] = fac[1] = 1;
    facn[1] = n;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < NCK_MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        facn[i] = facn[i-1] * (n-i+1) % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
ll modinv(ll a, ll mod){
  return myPow(a, mod - 2, mod);
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return facn[k] * finv[k] % MOD;
}

int main(int argc, char const *argv[]) {
  ll n, a, b, ans;
  std::cin >> n >> a >> b;
  COMinit(n);
  ans = (myPow(2,n,MOD)-1 + MOD) %MOD;
  ans = (ans - COM(n,a)+MOD)%MOD;
  ans = (ans -COM(n,b)+MOD)%MOD;
  std::cout << ans << '\n';
  return 0;
}
