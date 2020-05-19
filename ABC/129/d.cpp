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
    int h, w;
    cin >> h >> w;
    char grid[h][w];
    REP(i,h) REP(j,w)
    {
        cin >> grid[i][j];
    }
    int w_max = 0;
    int h_max = 0;

    int w_grid[h][w];
    int h_grid[h][w];
    REP(i,h) REP(j,w)
    {
        w_grid[i][j] = 0;
        h_grid[i][j] = 0;
    }

    REP(i,h)
    {   
        int tmp = 0;
        int _tmp = 0;
        int start = 0;
        int end = 0;
        REP(j,w)
        {
            if (grid[i][j] == '.') _tmp++;
            else
            {   
                end = j;
                FOR(k,start,end-1)
                    w_grid[i][k] = _tmp;
                start = j + 1;
                _tmp = 0;
            }   
        }
        end = w-1;
        FOR(k,start,end)
            w_grid[i][k] = _tmp;

        tmp = _tmp;
        _tmp = 0;
    }

    REP(j, w)
    {
        int tmp = 0;
        int _tmp = 0;
        int start = 0;
        int end = 0;
        REP(i, h)
        {
            if (grid[i][j] == '.')
                _tmp++;
            else
            {
                
                end = i;
                FOR(k, start, end-1)
                    h_grid[k][j] = _tmp;
                start = i + 1;
                _tmp = 0;
            }
        }
        end = h-1;

        FOR(k, start, end)
            h_grid[k][j] = _tmp;

        tmp = _tmp;
        _tmp = 0;

    }

    int ans = 0;

    REP(i,h) REP(j,w)
    {
        if (ans < h_grid[i][j] + w_grid[i][j])
            ans = h_grid[i][j] + w_grid[i][j];
    }
    cout << ans - 1 << endl;
    return 0;
}
