#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;


int main(int argc, char const *argv[]) {
  std::cin >> N;
  std::vector<int> v;
  std::vector<int> before;

  for (size_t i = 0; i < N; i++) {
    int c;
    std::cin >> c;
    v.push_back(c);
    before.push_back(c);
  }

  std::sort(v.begin(), v.end());
  for (size_t i = 0; i < N; i++) {
    int idx = before[i];
    for (size_t j = N-1; j > 0; j--) {
      // std::cout << "here" << '\n';
      if (idx != v[j]) {
        std::cout << v[j] << '\n';
        break;
      } else {
        std::cout << v[j-1] << '\n';
        break;
      }
    }
  }


  return 0;
}
