//深さ優先探索
#include <iostream>

using namespace std;

int n,k;
int list[10000];

bool dfs(int i, int sum) {
  if (i == n) return k == sum;  //n個のリストを使うか使わないかを決め終わったとき作れるかどうか
  if (dfs(i+1,sum)) return true;  //i番目の要素を使わないとき
  if (dfs(i+1,sum+list[i])) return true;  //i番目の要素を使うとき
  return false; //
}



int main(int argc, char const *argv[]) {

  bool a;

  std::cin >> n;
  for (size_t i = 0; i < n; i++) {
    std::cin >> list[i];
  }
  std::cin >> k;
  a = dfs(0,0);
  if (a) std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';
  return 0;

}
