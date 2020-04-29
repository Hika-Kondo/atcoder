#include <bits/stdc++.h>

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
#define S secon

vector< ll > divisor(ll n) {
  vector< ll > ret;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      ret.PB(i);
      if(i * i != n) ret.PB(n / i);
    }
  }
  sort(ALL(ret));
  return (ret);
}

int main(int argc, char const *argv[]) {
  ll n; std::cin >> n;
  std::vector<ll> yakusu = divisor(n);
  ll size = SIZE(yakusu);
  if (size % 2 == 1) std::cout << 2 * yakusu[size/2]  - 2 << '\n';
  else std::cout << yakusu[size/2-1] + yakusu[size/2] - 2 << '\n';
  return 0;
}
