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
    int n;
    map<int,vector<P>> tree;
    cin >> n;
    REP(i,n-1)
    {
        int u,v,w;
        cin >> u >> v >> w;

        tree[u - 1].PB(make_pair(v - 1, w % 2));
        tree[v - 1].PB(make_pair(u - 1, w % 2));
    }


    vector<int> ans(n, -1);
    queue<int> que;
    que.push(0);
    ans[0] = 0;
    while (!que.empty())
    {
        int now = que.front();que.pop();
        auto nodes = tree[now];
        REP(i,SIZE(nodes))
        {
            if (ans[nodes[i].F] == -1)
            {
                ans[nodes[i].F] = (nodes[i].S + ans[now]) % 2;
                que.push(nodes[i].F);
            }
            
        }
    }
    

    REP(i,n)
        cout << ans[i] << endl;

    return 0;
}
