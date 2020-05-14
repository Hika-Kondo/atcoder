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
    cin >> n;
    vector<int> a(n);
    REP(i,n)
        cin >> a[i];
    
    // 逆順で探す.
    // 自分が倍数のうち一番大きいときはそのままやる
    // 約数として一番小さくないときは上の約数のみ参照する
    int ans[n]={0};
    REPD(i,n)
    {
        int sho = n/(i+1);
        if (sho == 1)
        {
            ans[i] = a[i];
        } else
        {
            ll counter = 0;
            FOR(roop,2,sho)
            {
                int tmp = (i + 1) * roop - 1;
                if (ans[tmp] == 1)
                {
                    counter++;
                }
                
            }
            if (counter%2==a[i]) 
                continue;
            else
                ans[i] = 1;
        }
    }
    ll ans_counter = 0;
    vector<ll> ansvec;
    REP(i,n)
    {
        if (ans[i])
        {
            ans_counter++;
            ansvec.PB(i+1);
        }
    }

    cout << ans_counter << endl;
    if (ans_counter != 0)
    {
        REP(i,SIZE(ansvec))
            cout << ansvec[i] << " ";
        cout << endl;
    }
    return 0;
}
