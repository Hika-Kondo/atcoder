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

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<P> p(n);
    REP(i,n)
        cin >> p[i].S >> p[i].F;
    sort(ALL(p));
    int now = 0;
    REP(i,n)
    {
        now += p[i].S;
        if (now > p[i].F)
        {
            cout << "No" << endl;
            return 0;
        }
    }    

    cout << "Yes" << endl;
    return 0;
}


// int main(int argc, char const *argv[]) {
//     int n;
//     cin >> n;
    
//     map<int,priority_queue<int>> ma;
//     priority_queue<int, vector<int>, greater<int>> q;
    
//     REP(i,n)
//     {
//         int a, b;
//         cin >> a >> b;
//         q.push(b);
//         ma[b].push(a);
//     }

//     int now = 0,top;

//     while(!q.empty())
//     {
//         top = q.top();
//         q.pop();
//         while (!ma[top].empty())
//         {
//             now+=ma[top].top();
//             ma[top].pop();
//             if (now > top)
//             {
//                 cout << "No" << endl;
//                 return 0;
//             }
//         }
//     }

//     cout << "Yes" << endl;

//     return 0;
// }
