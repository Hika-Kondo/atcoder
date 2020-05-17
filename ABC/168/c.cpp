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

const double PI = 3.14159265358979323846;

double yogen(double a, double b, double kaku)
{
    double tmp = pow(a,2) + pow(b,2) - 2 * a * b * cos(kaku);
    return sqrt(tmp);
}

double kaku(double h, double m)
{
    double hun = 60 * h + m;
    double rad = hun / 360 * PI;
    return rad;
}

int main(int argc, char const *argv[]) {
    double a, b, h, m;
    // cin >> a >> b >> h >> m;
    scanf("%lf%lf%lf%lf",&a,&b,&h,&m);

    double hour_rad = kaku(h,m);
    double min_rad = kaku(0,m)* 12;
    double rad = abs(min_rad - hour_rad);
    double ans = yogen(a,b,rad);
    // cout << ans << endl;
    printf("%20.20lf",ans);
    printf("\n");
    return 0;
}
