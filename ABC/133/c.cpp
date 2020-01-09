#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(int argc, char const *argv[]) {
  long long l, r, i, j; cin >> l >> r;
  long long ans = 100000;

  // int ans = 2020;
  for ( i = l; i < r + 1; i++) {
    for ( j = i + 1; j < r + 1; j++) {
      ans = min(ans, i % 2019 * j % 2019);
      if (ans == 0) break;
    }
    if (ans == 0) break;
  }
  std::cout << ans << '\n';
  return 0;
}
