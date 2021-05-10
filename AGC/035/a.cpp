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
    int n; cin >> n; 
    vector<int> a(n); REP(i,n) cin >> a[i];

    // 全部0かどうか確認する
    bool flag = true;
    REP(i,n) 
        if (a[i] != 0) flag = false;
    if (flag) {
        cout << "Yes" << endl;
        return 0;
    } 
    
    // 全部同じでないときは要素の数が3の倍数でなければならない
    if (n % 3 != 0) {
        cout << "No" << endl;
        return 0;
    }

    // 全部同じでないときは要素の数が3種類か2種類でなければならない
    map<int,int> itm;
    REP(i,n) itm[a[i]]++;
    if (SIZE(itm) == 2) {
        if (itm[0] == 0) {
            cout << "No" << endl;
            return 0;
        }
        else if (itm[0] == n/3) {
            cout << "Yes" << endl;
        }
    }

    else if (SIZE(itm) == 3) {
        flag = true;
        vector<int> keys;
        for (auto now : itm) {
            keys.PB(now.F);
            if (now.S != n/3) flag=false;
        }
        if (!flag) {
            cout << "No" << endl;
            return 0;
        }
        if (keys[0] ^ keys[1] ^ keys[2] == 0) cout << "Yes" << endl;
        /* cout << keys[0] << " " << keys[1] << " " << keys[2] << " " << (keys[0] ^ keys[1] ^ keys[2]) << endl; */
    }

    else cout << "No" << endl;

    return 0;
}
