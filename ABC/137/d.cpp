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
    int n,m; cin >> n >> m;
    vector<vector<int>> jobs(m); REP(i,n) {
        int a, b; cin >> a >> b;
        if (a > m) continue;
        jobs[m-a].PB(b);
    }

    ll ans = 0;
    priority_queue<int> que;
    // jobsのkeyはお金をもらえるタイミングで最も遅いときvalueは報酬
    // 逆順でやることでqueに入る要素はi日目では全部補修を受けられる
    REPD(i,m) { 
        for(auto j : jobs[i]) que.push(j);
        if (!que.empty()) {
            int top_item = que.top(); que.pop();
            ans+=top_item;
        }
    }
    cout << ans << "\n";
    return 0;
}


