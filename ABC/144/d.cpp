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
#define S second


int main(int argc, char const *argv[]) {
  double a, b, x; cin >> a >> b >> x;
  bool flag = (a * a * b / 2 < x);
  double rad;
  if (flag) {
    double diff = a * a * b - x;
    rad = atan2(2 * diff/pow(a,2),a);
  } else {
    rad = atan2(b,2 * x / (a * b));
  }
  double ans = rad/ (2 * acos(-1)) * 360;
  printf("%.10f\n",ans);
  return 0;
}
