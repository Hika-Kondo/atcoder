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

std::string s,t;
std::vector<std::vector<int>> dp;

int DP(int n, int m) {
  FOR(i,1,n) FOR(j,1,m) {
    if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i-1][j-1],max(dp[i][j-1],dp[i-1][j]));
    else dp[i][j] = max(dp[i-1][j-1]+1,max(dp[i-1][j],dp[i][j-1]));
  }
  return dp[n][m];
}

int main(int argc, char const *argv[]) {
  int n,m; std::cin >> n >> m;
  std::cin >> s >> t;
  dp.assign(n+1,std::vector<int>(m+1,0));
  int ans = DP(n,m);
  std::cout << ans << '\n';
  return 0;
}
