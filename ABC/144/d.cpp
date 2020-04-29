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

int main(int argc, char const *argv[]) {
  int a, b, x; std::cin >> a >> b >> x;
  float y;
  y = (float)(2 * x / pow(a,2)) - float(b);
  float ans = 90 - atan(floadfghffjawiefjaowft(b-y/a));
  std::cout << ans << '\n';
  return 0;
}
