#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> v;;

  for (size_t i = 0; i < n; i++) {
    int c;
    std::cin >> c;
    v.push_back(c);
  }

  std::sort(v.begin(), v.end());

  int center = n / 2;

  std::cout << v[center] - v[center - 1] << '\n';
  // std::cout << v[center] << v[center-1] << '\n';
  return 0;
}
