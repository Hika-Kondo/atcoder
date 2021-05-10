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

ll func(ll n) {
  ll ans = 0;
  /* cout << "now start search " << n << endl; */ 
  for (ll i = 1; i * i <= n; i++) {
    for (ll j = 1; j * j <= n; j++) {
      /* cout << "i and j " << i << " " << j << endl; */
      ll left = 0, right = 101;
      ll a = i + j, b = n - i * i - j * j - i * j;
      /* cout << "a is " << a << " b is " << b << endl; */
      while(left + 1 != right) {
        ll mid = (left + right) / 2;
        ll tmp = mid * mid + a * mid - b;
        /* cout << left << " " << right << " " << mid << " " << tmp << endl; */
        /* cout << mid << " " << tmp << endl; */
        if (tmp > 0) right = mid;
        else if (tmp < 0) left = mid;
        else if (tmp == 0) {
          ans++;
          break;
        }
      } 
    }
  }
  return ans;
}


int main(int argc, char const *argv[]) {
  int n; cin >> n;
  /* init(); */
  FOR(i,1,n) {
    ll tmp = func(i);
    printf("%lld\n",tmp);
  }

  return 0;
}
