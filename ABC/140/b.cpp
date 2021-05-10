#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
using ll = long long;
int main(){
  int n;
  cin >> n;
  vector<int>a(n),b(n),c(n-1);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> b[i];
  rep(i,n-1)cin>> c[i];
  int sum=0;
  rep(i,n)sum += b[i];
  rep(i,n-1){
  	if(a[i] +1 == a[i+1])sum += c[a[i] - 1];
  }
  cout << sum <<endl;
  
  
  
  return 0;
}

