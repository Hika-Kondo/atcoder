#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int x;
  std::cin >> x;
  int flag = 0;
  if (x == 1 || x == 2) {
    std::cout << x << '\n';
    //std::cout << "here" << '\n';
    return 0;
  }
  while (true) {
    flag = 0;
    for (int i = 2; i <= x/2+ 1; i++) {
      if (x % i == 0) flag =1;
      //std::cout << "x " << x << " " << "i " << i  << " x % i " << x%i << " flag " << flag << '\n';
    }
    if (flag == 0) break;
    x++;
    //std::cout << x << " " << flag  << '\n';

  }
  std::cout << x << '\n';
  return 0;
}
