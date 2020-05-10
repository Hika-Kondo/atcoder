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
    ll n,k; cin >> n >> k; // nは街の個数,kは高橋王が移動する回数
    vector<ll> a(n); REP(i,n) {
        ll temp; cin >> temp;
        a[i] = temp - 1; // i番目の村の転送先
    }

    // 3周分だけ周りroopを見つける
    map<ll,ll> roop_finder; //通った回数をカウントする通った回数が一回であればroop外2回以上であればroopのメンバー
    vector<ll> roop; //roop担っているものを順番に入れたもの.
    vector<ll> road_to_roop; // roopに入るまでの順番を記録したもの
    // ll jun_idx = 0, road_idx = 0; // jun_idx roopのメンバーのidx road_idx roopまでのインデックス
    ll temp = 0;
    REP(i,2*n) {
        roop_finder[temp]++;
        if (roop_finder[temp] == 2) {
            roop.PB(temp);
        }
        temp = a[temp];
    }

    ll road = 0;

    REP(i,SIZE(roop_finder)) {
        if (roop_finder[i] == 1) road++;
    }

    ll roop_num = SIZE(roop);

    temp = k - road;
    ll idx = temp%roop_num;
    if (k < n) {
        temp = 0;
        REP(i,k) {
            temp = a[temp];
        }
        cout << temp + 1 << "\n";
    }
    else cout << roop[min(idx,temp)]+1 << "\n";

    return 0;
}
