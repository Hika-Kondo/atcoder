#include<bits/stdc++.h>

using namespace std;

int main() {
  int a,b,ans = 0; cin >> a >> b;
  if (b > a) swap(a,b);
  ans += a; a--;
  if (b > a) swap(a,b);
  ans += a;
  cout << ans << endl;
}
