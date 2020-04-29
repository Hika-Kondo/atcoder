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
  int n; std::cin >> n;
  std::vector<int> l(n); REP(i,n) std::cin >> l[i];
  sort(ALL(l));
  int ans = 0;
  REP(i,n-1) FOR(j,i+1,n-1) {
    if (i == n-1 || j == n-1) continue;
    int a = l[i],b = l[j]; // 問題分でのa,b a < b

    // c < a + bを二分探索
    int left = j+1, right = n;
    while (left+1 < right) {
      int center = (left+right)/2, sum = a + b;
      if (l[center] < sum) left=center;
      else right = center;
    }
    // c > b - cを二分探索
    int LEFT = j,RIGHT = left;
    while (LEFT+1 < RIGHT) {
      int CENTER = (LEFT+RIGHT)/2, sub = b - a;
      if (l[CENTER] <= sub) LEFT = CENTER;
      else RIGHT = CENTER;
    }
    // std::cout << "a " << a << "\tb " << b << "\tleft " << l[RIGHT] << "\tright " << l[left] << '\n';
    // std::cout << a+b << '\n';
    // std::cout << "left " << left << "\tRIGHT" << RIGHT << '\n';
    if (left == j+1) {
      int c = l[left];
      if (c >= a + b) continue;
    }
    if (RIGHT == n-1){
      int c = l[RIGHT];
      if (c <= b - a) continue;
    }
    ans+=left-RIGHT+1;
    // std::cout << "ans " << ans << '\n';
  }
  std::cout << ans << '\n';
  return 0;
}
