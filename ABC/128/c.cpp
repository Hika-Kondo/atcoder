#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

//マクロ
#define REP(i, n) for (ll i = 0; i < (ll)(n); i++)
#define REPD(i, n) for (ll i = (ll)(n)-1; i >= 0; i--)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define FORD(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(x) (x).begin(), (x).end() //sortなどの引数を省略したい
#define SIZE(x) ((ll)(x).size())      //sizeをsize_tからllに直しておく
#define MAX(x) *max_element(ALL(x))
#define INF 1000000000000 //10^12
#define MOD 10000007      //10^9+7
#define PB push_back
#define MP make_pair
#define F first
#define S second

int main(int argc, char const *argv[])
{
    // スイッチの個数n, 電球の個数m
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<vector<int>> s(m);

    REP(i,m)
    {
        scanf("%d", &k);
        REP(j,k)
        {
            int tmp;
            scanf("%d", &tmp);
            s[i].PB(tmp - 1);
        }
    }

    int p[m];
    REP(i,m)
        scanf("%d", &p[i]);
    

    int ans = 0;
    // 全探索
    REP(i,pow(2,n))
    {   
        int swch_cnt[m] = {0};
        // スイッチ jはスイッチのインデックス
        REP(j, n)
        {
            // 1の時スイッチおん
            if (i & (1 << j))
            {
                // k:電球の番号
                REP(k,m)
                {
                    // l:k番目の電球につながっているスイッチのインデックス
                    REP(l,SIZE(s[k]))
                    {
                        if (j == s[k][l])
                            swch_cnt[k]++;
                    }
                }
            }
            
        }
        // 設定に有っているかどうかを判定する
        bool flag = true;
        REP(k,m)
        {
            if (p[k] != (swch_cnt[k] % 2))
                flag = false;
        }
        if (flag)
            ans++;
    }


    printf("%d\n",ans);
    return 0;
}
