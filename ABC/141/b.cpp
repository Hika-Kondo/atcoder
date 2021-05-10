#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)

int main() {
  char s[100] = {'0'}; cin >> s;
  REP(i,100) {
    if ((i + 1) % 2) {
      if (s[i] == 'L') {
        cout << "No" << endl;
        return 0;
      }
    } else {
      if (s[i] == 'R') {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}
