#include <bits/stdc++.h>

using namespace std;


int main(){
  long long a,b,k;
	cin>>a>>b>>k;

	if(k<a) cout<<a-k<<" "<<b<<endl;
	else if(k<=a+b) cout<<0<<" "<<b-(k-a)<<endl;
	else cout<<0<<" "<<0<<endl;

	return 0;
}
