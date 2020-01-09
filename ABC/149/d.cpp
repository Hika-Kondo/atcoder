#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
  int n,k,r,s,p;
  int points = 0;
  std::string t;
  std::cin >> n >> k;
  std::cin >> r >> s >> p;
  std::cin >> t;
  for (int i = 0; i < n - k; i++) {
    if (t[i] == t[i + k]) t[i + k] = 'j';
  }
  //std::cout << t << '\n';
  for (int i = 0; i < n; i++) {
    if (t[i] == 's') points += r;
    else if (t[i] == 'p') points += s;
    else if (t[i] == 'r') points += p;

  }
  std::cout << points << '\n';
  return 0;
}
