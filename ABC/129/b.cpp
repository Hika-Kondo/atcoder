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
    int n;
    cin >> n;
    vector<int> w(n);
    int hanbun = 0;
    cin >> w[0];
    FOR(i, 1, n - 1)
    {
        int _w;
        cin >> _w;
        w[i] += w[i - 1] + _w;
    }

    hanbun /= 2;
    ll sa = INF;
    ll tmp = 0;
    REP(i, n - 1)
    {
        int left = w[i], right = w[n - 1] - w[i];
        if (sa > abs(right - left))
            sa = abs(right - left);
    }
    cout << sa << endl;
    return 0;
}
