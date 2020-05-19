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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    REP(i, n)
    {
        cin >> a[i];
    }

    ll right = 0;
    ll sum = 0, tot = 0;

    // 条件を満たさないやつを求めて引く
    REP(left, n)
    {   
        // breakした時にrightは含まれないつまり条件を満たす区間は(right-1) - left + 1 = right - left
        // [left,right) rightは含まないようにする.
        while (right < n && sum + a[right] < k)
        {
            sum += a[right];
            right++;
        }

        if (right == left)
        {
            right++;
        }
        else 
        {
            tot += right - left;
            sum -= a[left];
        }
    }

    ll ans = n * (n + 1) / 2 - tot;
    cout << ans << endl;
    return 0;
}
