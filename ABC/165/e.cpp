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
  int n, m; cin >> n >> m;
  vector<P> ans;
  /* mの最大値が偶数か奇数化を判定する */ 
  int max_m = (n - 1) / 2;
  /* cout << max_m << endl; */
  if (max_m % 2) {
    int c = n / 2;
    /* cout << "now start 前半" << endl; */
    REP(i,max_m/2) {
      /* cout << c/2 - i << " " << c/2 + i + 2 << endl; */
      ans.emplace_back(c/2 - i,c/2 + i + 2);
    }
    if ((n - c) % 2) c = ((c + 1) + n) / 2;
    else c = ((c + 1) + n) / 2 + 1;
    /* cout << "c " << c << "now start 後半" << endl; */
    REP(i,max_m - max_m / 2) {
      /* cout << c + i << " " << n - i << endl; */ 
      ans.emplace_back(c - i - 1,c + i);
    }
  } else {
    int c = (n + 1) / 2;
    /* cout << "now start 前半" << endl; */
    REP(i,max_m/2) {
      /* cout << c/2 - i << " " << c/2 + i + 2 << endl; */
      ans.emplace_back(c/2 - i,c/2 + i + 2);
    }
    if ((n - c) % 2) c = ((c + 1) + n) / 2;
    else c = ((c + 1) + n) / 2 + 1;
    /* cout << "c " << c << "now start 後半" << endl; */
    REP(i,max_m - max_m / 2) {
      /* cout << c + i << " " << n - i << endl; */ 
      ans.emplace_back(c - i - 1,c + i);
    }
 
  }
  REP(i,m) cout << ans[i].F << " " << ans[i].S << endl;
  return 0;
}
