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
  ll n; cin >> n;
  vector<ll> ans(n + 1,1);
  FOR(i,2,n) {
    int now=i;
    ans[now] ++ ;
    /* cout << "now num is " << now << endl; */
    while (true) {
      now += i;
      if (now > n) break;
      /* cout << now << endl; */
      ans[now]++;
    }
  }


  ll res = 0;
  FOR(i,1,n) {
    /* cout << "now number is " << i << " num item " << ans[i] << " sum is  " << i * ans[i] << endl; */
    res += i * ans[i];
  }

  cout << res << endl;
  return 0;
}
