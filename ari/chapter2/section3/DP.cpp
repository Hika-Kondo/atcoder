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

std::vector<P> item;
std::vector<std::vector<int> > dp;
int n,w;

int DP() {
  REPD(i,n){
    REP(j,w+1) {
      if (item[i].F > j) {
        dp[i][j] = dp[i+1][j];
      } else {
        dp[i][j] = max(dp[i+1][j],dp[i+1][j-item[i].F]+item[i].S);
      }
    }
  }
  return dp[0][w];
}
int main(int argc, char const *argv[]) {
  std::cin >> n >> w;
  item.resize(n); REP(i,n) std::cin >> item[i].F >> item[i].S; // PのFは重さ,PのSは価値
  dp.assign(n+1,std::vector<int>(w+1,0));
  // dp[n].assign(std::vector<int>(w+1,0));
  int ans = DP();
  std::cout << ans << '\n';
  return 0;
}
