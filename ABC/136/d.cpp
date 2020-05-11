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

int main(int argc, char const *argv[]) {
    string s; cin >> s;
    ll r[SIZE(s)] = {0}, l[SIZE(s)]={0}, ans[SIZE(s)]={0}, memo[SIZE(s)]={0};
    ll temp = 0;
    
    // r[0] = 1;
    REP(i,SIZE(s)) {
        if (s[i] == 'R') temp++;
        else {
            r[i-1] = temp;
            temp = 0;
        }
    }

    // REP(i,SIZE(s)) cout << r[i] << " ";
    // cout << "\n";
    
    temp = 0;
    // l[SIZE(s)-1] = 1;
    REPD(i,SIZE(s)) {
        if (s[i] == 'L') temp++;
        else {
            l[i+1] = temp;
            temp = 0;
        }
    }

    // REP(i,SIZE(s)) cout << l[i] << " ";
    // cout << "\n";

    REP(i,SIZE(s)-1) {
        if (s[i] == 'R' && s[i+1] == 'L') {
            ll sum = r[i] + l[i+1];
            if (sum % 2 == 0) {
                ans[i] = sum/2;
                ans[i+1] = sum/2;
            }
            else {
                ans[i] = l[i+1]/2 + r[i]/2 + r[i]%2;
                ans[i+1] = l[i+1]/2 + l[i+1]%2 + r[i]/2;
            }
        }
    }

    REP(i,SIZE(s)) cout << ans[i] << " ";
    cout << "\n";
}
