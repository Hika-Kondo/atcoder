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

// int main(int argc, char const *argv[])
// {
//     int n, p;
//     scanf("%d", &n);
//     char s[110];
//     pair<pair<string, int>, int> pir[n];

//     REP(i, n)
//     {
//         scanf("%s%d", s, &p);
//         pir[i] = make_pair(make_pair(s, -1 * p), i + 1);
//     }

//     sort(pir, pir + n);
//     REP(i, n)
//         printf("%d\n", pir[i].second);
        
//     return 0;
// }

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    
    // 都市名, 点数, id
    vector<tuple<string, int, int>> ipt; 

    REP(i,n)
    {
        char s[200]; int p;
        scanf("%s%d", s, &p);
        p = -1 * p;
        int idx = i + 1;
        // ipt.PB(tie(s, p, idx));
        ipt.emplace_back(s,p,i + 1);
    }

    sort(ALL(ipt));
    REP(i,n)
    {
        string s; int p, idx;
        tie(s,p,idx) = ipt[i];
        printf("%d\n", idx);
    }
    return 0;
}

