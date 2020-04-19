//参考：http://ehafib.hatenablog.com/entry/2015/12/23/164517
//インクルード
#include<algorithm>//sort,二分探索,など
#include<bitset>//固定長bit集合
#include<cmath>//pow,logなど
#include<complex>//複素数
#include<deque>//両端アクセスのキュー
#include<functional>//sortのgreater
#include<iomanip>//setprecision(浮動小数点の出力の誤差)
#include<iostream>//入出力
#include<map>//map(辞書)
#include<numeric>//iota(整数列の生成),gcdとlcm(c++17)
#include<queue>//キュー
#include<set>//集合
#include<stack>//スタック
#include<string>//文字列
#include<unordered_map>//イテレータあるけど順序保持しないmap
#include<unordered_set>//イテレータあるけど順序保持しないset
#include<utility>//pair
#include<vector>//可変長配列

using namespace std;
typedef long long ll;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000
#define NCK_MAX 510000
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main(int argc, char const *argv[]) {
  int n,m;std::cin >> n >> m;
  std::map<int, std::vector<std::string>> mp;
  REP(i,m) {
    int temp_p;
    std::string temp_s;
    std::cin >> temp_p >> temp_s;
    mp[temp_p].PB(temp_s);
  }
  int ans = 0;
  int ac_counter = 0;
  for (auto& x:mp){
    int temp=0;
    bool flag=false;
    for (auto & element : x.S) {
      if (element == "WA") temp++;
      else if (element == "AC") {
        ac_counter++;
        flag=true;
        break;
      }
    }
    if (flag) {
      ans+=temp;
    }
  }
  std::cout << ac_counter <<' ' << ans << '\n';

  return 0;
}
