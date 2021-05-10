#include <bits/stdc++.h>

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
#define NCK_MAX 510000
#define INF 1000000000000 //10^12
#define MOD 998244353
#define PB push_back
#define MP make_pair
#define F first
#define S second

ll myPow(ll x, ll n, ll m)
{
  if (n == 0)
    return 1;
  if (n % 2 == 0)
    return myPow(x * x % m, n / 2, m);
  else
    return x * myPow(x, n - 1, m) % m;
}

ll fac[NCK_MAX], finv[NCK_MAX], inv[NCK_MAX], facn[NCK_MAX];

// テーブルを作る前処理
void COMinit()
{
  fac[0] = fac[1] = 1;
  facn[1] = NCK_MAX;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < NCK_MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    facn[i] = facn[i - 1] * (NCK_MAX - i + 1) % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}
ll modinv(ll a, ll mod)
{
  return myPow(a, mod - 2, mod);
}

// 二項係数計算
long long COM(int n, int k)
{
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

int main() {
  COMinit();
  cout << COM(2,1) << endl;
}
