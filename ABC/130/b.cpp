#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> P;

//マクロ
#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=(ll)(n)-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=(a);i<=(b);i++)
#define FORD(i,a,b) for(ll i=(a);i>=(b);i--)
#define ALL(x) (x).begin(),(x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size()) //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000 //10^12
#define MOD 10000007 //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second

int ans[1000010]={-1};
int l[1000100] = {-1};

void solve(int n) 
{
    ans[0] = 0;
    REP(i,n)
    {
        ans[i+1] = ans[i] + l[i];  
    }
}

int main(int argc, char const *argv[]) {
    int n,x;
    cin >> n >> x; 
    REP(i,n)
        cin >> l[i];
    
    int tot = 0;
    solve(n);
    REP(i,n+1) 
    {
        if (ans[i] <= x)
            tot++;
    }

    cout << tot << endl;
    return 0;
}
