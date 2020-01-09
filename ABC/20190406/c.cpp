#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  long long N;
  std::vector<long long> v(5);
  std::cin >> N;
  for (size_t i = 0; i < 5; i++) {
    std::cin >> v[i];
  }
  sort(v.begin(),v.end());
  if (N % v[0] != 0)  std::cout << N / v[0] + 5 << '\n';
  else std::cout << N / v[0] + 4 << '\n';
  return 0;
}
