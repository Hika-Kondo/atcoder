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
    string s;
    cin >> s;

    int fi = (s[0] - '0') * 10 + (s[1] - '0');
    int se = (s[2] - '0') * 10 + (s[3] - '0');

    
    if (fi <= 12 && se <= 12)
        cout << "AMBIGUOUS" << endl;
    else if ((fi > 12 && se > 12) || (fi == 0 || se == 0))
        cout << "NA" << endl;
    else if (fi > 12 && se <= 12)
        cout << "YYMM" << endl;
    else 
        cout << "MMYY" << endl;
    return 0;
}
