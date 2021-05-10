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

set<ll> divisor(ll n) {
  set<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.insert(i);
      if (i * i != n) ret.insert(n / i);
    }
  }
  return ret ;
}

int main(int argc, char const *argv[]) {
  int n; cin >> n;
  ll _max = 1e6 + 5;
  int dp[_max] = {0};
  vector<int> a(n);
  
  REP(i,n) cin >> a[i];
  for (int i : a) {
    if (dp[i] != 0) {
      dp[i] = 2;
      continue;
    }
    for (int j = i; j <= _max; j += i) dp[j]++;
  }

  int ans = 0;
  for (int now : a) {
    if (dp[now] == 1) ans++;
  }
  cout << ans << endl;
}
