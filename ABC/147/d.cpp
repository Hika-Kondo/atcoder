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

int main(int argc, char const *argv[]) {
  int n; std::cin >> n;
  std::vector<ll> a(n,0); REP(i,n) std::cin >> a[i];
  // 各桁ごとにxnor演算をする.
  // 同じ入力の時xnor0だから,各々の桁についてすべてxnorをすることは0のやつの数と1のやつの数の積である.
  ll ans=0;
  REP(i,60) {
    // a[i]についてのi桁目の0の数と1の数について求める.

    ll x=0;
    // 1のときカウント用

    REP(j,n) if (a[j] >> i&1) x++;
    //a[j]をi桁bitシフトした時の値に対して1とandを取るそれがtrue(1)の時その桁1である.

    ll temp;
    temp=x*(n-x)%MOD;
    //0の数字の数×1の数字の数

    REP(j,i) temp=temp*2%MOD;
    ans+=temp;
    ans%=MOD;
  }
  std::cout << ans << '\n';
}
