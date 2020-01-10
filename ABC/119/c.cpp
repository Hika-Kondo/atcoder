#include <bits/stdc++.h>

using namespace std;

int N, A, B, C;
std::vector<int> l;
int dfs(int cur, int a, int b, int c) {
  if (cur == N) {
    if (min(min(a,b),c) > 0) return abs(a-A) + abs(b-B) + abs(c-C) -30;
    else return 100000;

  }
  int ret0 = dfs(cur+1, a, b, c);
  int ret1 = dfs(cur+1, a+l[cur], b, c) + 10;
  int ret2 = dfs(cur+1, a, b+l[cur], c) + 10;
  int ret3 = dfs(cur+1, a, b, c+l[cur]) + 10;
  return min(min(min(ret0,ret1),ret2),ret3);
}

int main(int argc, char const *argv[]) {

  std::cin >> N >> A >> B >> C;
  for (int i=0; i<N; i++) {
    int z; std::cin >> z;
    l.push_back(z);
  }
  int ans = dfs(0,0,0,0);
  std::cout << ans << '\n';

  return 0;
}
