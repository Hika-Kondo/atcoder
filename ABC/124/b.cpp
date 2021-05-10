#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(ll i = 0; i < (ll)n; i++)
#define ll long long

int main() {
  int n; cin >> n;
  int itm[n]; rep(i,n) cin >> itm[i];
  int min = 0;
  int ans = 0;
  rep(i,n) {
    if (itm[i] > min) min = itm[i];
    if (itm[i] >= min) ans++; 
  }
  cout << ans << endl;
}
