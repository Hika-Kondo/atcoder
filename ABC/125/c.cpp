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
  int n; cin >> n; vector<ll> a(n); REP(i,n) cin >> a[i];
  
  vector<ll> gcd(n), rgcd(n);
  gcd[0] = a[0]; rgcd[n-1] = a[n-1];
  REP(i,n-1) {
    gcd[i+1] = __gcd(a[i+1],gcd[i]);
    rgcd[n-i-2] = __gcd(a[n-i-2],rgcd[n-i-1]);
  }
  
  vector<ll> ans(n);
  ans[0] = rgcd[1];
  ans[n-1] = gcd[n-2];

  REP(i,n-2) {
    ans[i+1] = __gcd(gcd[i],rgcd[i+2]);
  }
  sort(ALL(ans));

  cout << ans[n-1] << endl;
  return 0;
}
