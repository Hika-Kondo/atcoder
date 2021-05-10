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
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main(int argc, char const *argv[]) {
  int n; cin >> n;
  vector<ll> a(n); REP(i,n) cin >> a[i];
  vector<ll> _abs(n);
  ll counter = 0;
  REP(i,n) {
    if (a[i] < 0) {
      counter++;
    }
    _abs[i] = abs(a[i]);
  }

  sort(ALL(_abs));
  ll ans = 0;
  if (counter % 2) {
    REP(i,n) ans += _abs[i];
    ans -= 2 * _abs[0];
  } else {
    REP(i,n) ans += _abs[i];
  }
  cout << ans << endl;
  return 0;
}
