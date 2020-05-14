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
    int a[n];
    REP(i, n)
    cin >> a[i];

    // A1 + A2 + ... + An = X1 + X2 + ... + Xn = Sまた
    // Ai = (Xi + X(i+1)) / 2 => 2 * Ai = Xi + X(i+1)
    // X1 = S - 2 * (X2 + X4 + ... Xn-1)
    // 漸化式 X(i+1) = 2 * Ai - Xi

    // Xiを求める
    ll x[n] = {0}, s = 0;

    REP(i, n)
    s += a[i];

    for (ll i = 1; i <= n - 2; i += 2)
    {
        s -= 2 * a[i];
    }
    x[0] = s;

    FOR(i, 1, n - 1)
    {
        x[i] = 2 * a[i - 1] - x[i - 1];
    }

    REP(i, n)
    {
        cout << x[i];
        if (i == n - 1)
            cout << endl;
        else
            cout << " ";
    }
}
