#include <bits/stdc++.h>

using namespace std;

long long int gcd(long long int a, long long int b) {
  a = max(a,b);
  b = min(a,b);

  if (a % b == 0) return b;
  return gcd(b,a%b);

}

int main(int argc, char const *argv[]) {
  int n;
  std::cin >> n;
  std::vector<long long int> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i];

  long long int max = 0;

  std::vector<long long int> r(n),l(n),t(n);
  l[0] = a[0];
  r[n-1] = a[n-1];

  for (size_t i = 1; i < n; i++) {
    l[i] = gcd(l[i-1],a[i]);
  }

  for (int i = n-2; i >= 0; i--) {
    r[i] = gcd(a[i],r[i + 1]);
  }
  t[0] = r[1];
  t[n-1] = r[n-2];
  for (int i = 1; i < n-1; i++ ) {
    t[i] = gcd(l[i-1],r[i+1]);
  }
  sort(t.begin(),t.end());
  std::cout << t[n-1] << '\n';
  return 0;
}
