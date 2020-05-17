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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> path(n);
    int ans[n]; // 答えを格納する配列
    REP(i,n)
        ans[i] = -1;
    
    queue<int> que;
    
    REP(i,m) 
    {
        int a,b;
        cin >> a >> b;
        path[a-1].PB(b-1);
        path[b-1].PB(a-1);
    }
    que.push(0);


    ans[0] = 0;
    while (!que.empty())
    {
        int now = que.front(); //現在の場所
        que.pop();

        REP(i,SIZE(path[now]))
        {
            int tmp = path[now][i];
            if (tmp == now) continue;
            if (ans[tmp] != -1)
                continue;
            else
            {
                ans[tmp] = now;
                que.push(tmp);
            }

        }
    }

    REP(i,n)
    {
        if (ans[i] == -1)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    
    FOR(i,1,n-1)
        cout << ans[i]+1 << endl;

    return 0;
}
