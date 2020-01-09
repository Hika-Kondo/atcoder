#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, Q; std::cin >> N >> Q;
  std::string S; std::cin >> S;

  int l[N], r[N];
  for (int i = 0; i < Q; i++ ) std::cin >> l[i] >> r[i];

  int res[N]; res[0] = 0;
  int counter = 0;
  for (int i = 0; i < N; i++) {
    if (S[i-1] == 'A' && S[i] == 'C') {
      counter++;
    }
    res[i] = counter;

  }
  for (size_t i = 0; i < Q; i++) {
    std::cout << res[r[i]-1] - res[l[i]-1] << '\n';
  }
  return 0;
}
