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


int n,m,x;
vector<vector<int>> a;
vector<int> c;



int main(int argc, char const *argv[]) {
    cin >> n >> m >> x; // n 本の数　m アルゴリズムの数　x 目標のスキル
    a.resize(n); c.resize(n);

    REP(i,n) {
        cin >> c[i];
        REP(j,m) {
            int temp;
            cin >> temp;
            a[i].PB(temp);
        }
    }

    ll ans = INF;
    REP(i, pow(2,n)) { //　本の組み合わせをbitシフトで計算
        ll temp[m] = {0};
        ll temp_money = 0;
        REP(j,n) { // j番目の本を買うか買わないかを判定
            if (i & (1<<j)) {
                REP(k,m) temp[k] += a[j][k];
                temp_money+= c[j];
            }
        }
        // cout << "temp ";
        // REP(i,m) cout << temp[i] << " ";
        // cout << temp_money << "\n";
        
        bool flag = true;
        REP(i,m) {
            if (temp[i] < x) {
                // cout << "here " << temp[i] << "\n";
                flag = false;
            }
        }
        if (flag && ans > temp_money) ans = temp_money;
    }
    
    if (ans != INF ) cout << ans << "\n";
    else cout << -1 << "\n";

    return 0;
}
