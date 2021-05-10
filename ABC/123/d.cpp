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


int X,Y,Z,K;
vector<ll> a,b,c;
set<ll> item;

bool check(ll p) {
  /* cout << p << endl; */
  int tot = 0;
  REP(i,X) REP(j,Y) REP(k,Z) {
    if (a[i] + b[j] + c[k] > p) {
      break;
    }
    else {
      tot++;
      item.insert(a[i] + b[j] + c[k]);
    }
    if (tot >= K) {
      /* cout << tot << " " << K << endl; */
      return false;
    } 
  }
  return true;
}


int main(int argc, char const *argv[]) {
  
  cin >> X >> Y >> Z >> K;

  a.resize(X); b.resize(Y); c.resize(Z);
  REP(i,X) cin >> a[i];
  REP(i,Y) cin >> b[i];
  REP(i,Z) cin >> c[i];

  sort(ALL(a)); sort(ALL(b)); sort(ALL(c));

  int max = a[X-1] + b[Y - 1] + c[Z - 1];
  ll left = 0, right = max + 1, center;
  while (left + 1 != right) {
    center = (left + right) / 2;
    if (check(center)) left = center;
    else right = center;
  }

  for (auto i : item) cout << i << endl;
  return 0;
}
