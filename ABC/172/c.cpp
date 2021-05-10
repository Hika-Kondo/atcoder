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
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> a(n), b(m); REP(i,n) cin >> a[i]; REP(i,m) cin >> b[i];
  vector<ll> sum_a(n + 1), sum_b(m + 1);
  
  FOR(i, 1, n) 
    sum_a[i] += sum_a[i-1] + a[i-1];
  
  FOR(i, 1, m)
    sum_b[i] += sum_b[i-1] + b[i-1];


  ll ans = 0, j = m;
  REP(i,n + 1) { 
    if (sum_a[i] > k) break;

    while (sum_b[j] > k - sum_a[i]) {
      j--;
    }
    ans = max(ans, i + j);
  }

  cout << ans << endl;
  return 0;
}
