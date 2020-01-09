#include <bits/stdc++.h>

using namespace std;

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
  if(a.first != b.first){
    return a.first < b.first;
  }else{
    return a.second < b.second;
  }
}

int main(int argc, char const *argv[]) {
  // 変数の宣言と入力
  int N, M; std::cin >> N >> M;
  std::vector<pair<long,long>> ab(N);
  for (size_t i = 0; i < N; i++) {
    int a,b;
    std::cin >> a >> b;
    ab[i] = make_pair(a, b);
  }
  sort(ab.begin(), ab.end(), compare_by_b);
  long long counter = 0;
  long long res = 0;
  for (int i = 0; i < N; i++) {
    long long cost = ab[i].first;
    long long num = ab[i].second;
    if (M - num <= 0) {
      res += M*cost;
      break;
    }
    else M -= num; res += num*cost;
  }
  std::cout << res << '\n';
  return 0;
}
