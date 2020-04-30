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



ll gcd(ll a, ll b) {
  if (a > b) swap(a,b);
  if (b % a == 0) return a;
  return gcd(b%a,a);
}

std::vector<ll> cd(ll a, ll b) {
  ll _gcd = gcd(a,b);
  std::vector<ll> res;
  ll _sqrt = sqrt(_gcd);
  FOR(i,1,_sqrt) {
    if (_gcd % i == 0) {
      res.PB(i);
      res.PB(_gcd/i);
    }
  }
  sort(ALL(res));
  return res;
}


int main(int argc, char const *argv[]) {
  ll a,b; std::cin >> a >> b;
  std::vector<ll> CD = cd(a,b);
  std::map<ll, ll> map;
  int ans = 0;
  CD.erase(unique(ALL(CD)), CD.end());
  ll multi = CD[0];
  FOR(i,1,SIZE(CD)-1) {
    // std::cout << "multi " << multi << '\n';
    // std::cout << "CD " << CD[i] << '\n';
    if (gcd(CD[i],multi) != 1) ans--;
    else multi=multi*CD[i];
  }
  // REP(i,SIZE(CD)) std::cout << CD[i] << '\n';
  std::cout << SIZE(CD) + ans << '\n';
  return 0;
}
