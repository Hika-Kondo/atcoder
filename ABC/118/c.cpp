#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  int mi = min(a,b);
  int ma = max(a,b);
  if (ma % mi == 0) {
    return mi;
  }
  else {
    return gcd(mi, ma%mi);
  }
}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i=0; i<n; i++) std::cin >> a[i];
  int temp;
  int res = gcd(a[0],a[1]);
  for (int i=1; i<n; i++ ) {
    temp = res;
    res = gcd(temp, a[i]);
  }
  std::cout << res << '\n';
  return 0;
}
