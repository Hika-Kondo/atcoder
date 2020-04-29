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

int bfs(int i, int rest_wight) {
  int res;
  if (i == SIZE(item)-1) res = 0;
  else if (item[i].F > rest_wight) res=bfs(i+1,rest_wight);
  else {
    res = max(bfs(i+1,rest_wight),bfs(i+1,rest_wight-item[i].F)+item[i].S);
  }
  return res;
}

int main(int argc, char const *argv[]) {
  int n,w; std::cin >> n >> w;
  item.resize(n); REP(i,n) std::cin >> item[i].F >> item[i].S; // PのFは重さ,PのSは価値
  int ans = bfs(0,w);
  std::cout << ans << '\n';
  return 0;
}
