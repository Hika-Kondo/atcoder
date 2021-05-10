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


ll count(ll n) {
  ll ans = 0;
  while (n != 0) {
    if (n % 2 == 1) ans++;
    n /= 2;
  }
  return ans;
}

ll func(ll n) {
  return n % count(n);
}

ll solve(ll n) {
  ll ans = 1;
  while (true) {
    ll tmp = func(n);
    n = tmp;
    if (n == 0) break;
    else ans++;
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  ll n; cin >> n;
  string s; cin >> s;
  ll string_num = 0, nisin = 1;

  REPD(i,n) {
    if (s[i] == '1') string_num += nisin;
    nisin *= 2;
  }

  nisin = 1;
  vector<ll> ans(n);
  REPD(i,n) {
    ll num = string_num;
    if (s[i] == '1') num -= nisin;
    else num += nisin;
    ans[i] = solve(num);
    nisin *= 2;
  }
  
  REP(i,n) cout << ans[i] << endl;
  return 0;
}
