#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for (ll i = 0; i < (ll)n; i++)
#define ll long long
#define P pair<int,int>

int main() {
  int n,k; cin >> n >> k;
  string ipt; cin >> ipt;
  int tot = 0;
  vector<int> itm;
  /* vector<int> cot; */
  rep(i,n) {
    if (i == 0) tot++;
    else if (ipt[i-1] == ipt[i]) tot++;
    else {
      itm.push_back(tot);
      tot = 1;
    }
  }
  itm.push_back(tot);

  int start;
  int tmp = 0;
  vector<int> wa(itm.size());
  wa[0] = itm[0];
  rep(i,itm.size()-1) wa[i+1] = wa[i] + itm[i+1];
  int ans = 0;

  if (ipt[0] == '0'){

    // start input with 0
    for (ll i = 0; i < wa.size(); i++) {
      if (i < 2 * k) 
        tmp = wa[i];

      else if (i % 2 == 0){
        tmp = wa[i] - wa[i - 2 * k];
      } 
      else 
        tmp = wa[i] - wa[i - 2 * k - 1];
      if (ans < tmp) ans = tmp;
    }
  } else {
    //start input with 1
    for (ll i = 0; i < wa.size(); i++) {
      if (i < 2 * k + 1)
        tmp = wa[i];
      else if (i % 2)
        tmp = wa[i] - wa[i - 2 * k];
      else
        tmp = wa[i] - wa[i - 2 * k - 1];
      if (ans < tmp)
        ans = tmp;
    }
  }
  cout << ans << endl;

  return 0;
  }
