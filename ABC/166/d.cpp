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

ll x;

int main(int argc, char const *argv[]) {
    std::cin >> x;
    ll b_left, b_right;
    FOR(a,0,1e5) {
        ll A = pow(a,5);
        // Aがxよりも大きい時普通の二分探索をすれば良い
        if (A > x) {
            b_left = -1; b_right = 1e3+1;
            while (b_left + 1 < b_right)
            {
                ll b = (b_left + b_right) / 2;
                ll B = pow(b,5);
                if (A - B <= x) b_right = b;
                else b_left = b;
            }
        } else {
            b_left = -1 * 1e3 -1; b_right = 1;
            while (b_left + 1 < b_right)
            {
                ll b = (b_left + b_right) / 2;
                ll B = pow(b,5);
                // std::cout << B << "\n";
                if (A - B <= x) b_right = b;
                else b_left = b;
            }
        }
        // std::cout << a << " " << b_left << " " << b_right << "\n";
        if (A - pow(b_right,5) == x) {
            std::cout << a << " " << b_right << "\n";
            return 0;
        }
        else if (A - pow(b_left,5) == x) {
            std::cout << a << " " << b_left << "\n";
            return 0;
        }
    }
    return 0;
}
