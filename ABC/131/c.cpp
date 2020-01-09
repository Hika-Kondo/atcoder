#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int gcd( long long int c, long long int d) {
  if (max(c,d) % min(c,d) == 0) return min(c,d);

  return gcd(min(c,d),max(c,d) % min(c,d));
}

long long int LCM(long long int c, long long int d) {
  return c * d / gcd(c,d);
}

long long int devide(long long int a, long long int s) {
  if (a % s == 0) return a/s;
  else return a/s + 1;
}

long long int solv(long long int a, long long int b, long long int c, long long int d) {
  long long int min_c, min_d, max_c,max_d, min_lcm, max_lcm, lcm;
  lcm = LCM(c,d);
  min_c = devide(a,c);
  max_c = b/c;
  min_d = devide(a,d);
  max_d = b/d;
  min_lcm = devide(a,lcm);
  max_lcm = b/lcm;
  return max_c + max_d - max_lcm - min_c - min_d + min_lcm + 1;
}

int main(int argc, char const *argv[]) {
  long long int a,b,c,d;
  std::cin >> a >> b >> c >> d;

  std::cout << b-a-solv(a, b, c, d) + 1 << '\n';
  return 0;
}
