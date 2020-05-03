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
    int n,l,p; std::cin >> n >> l >> p; // n:ガソスタの数 l:ゴールまでの距離 p:ガソリンタンクの初期値

    // a[i]:ガソリンスタンドのガソリン量 b[i]:ガソリンスタンドの距離
    int a[n+1],b[n+1]; REP(i,n) std::cin >> a[i]; REP(i,n) std::cin >> b[i];
    a[n] = 0;b[n] = l;
    priority_queue<int> que;

    // now:現在位置 ans:給油回数
    int now = 0, ans = 0;

    REP(i,n) {
        //今のままだと途中でガス欠になるときは給油する
        // std::cout << "a[i] - now " << a[i]-now << "\n";
        if (a[i] - now > p) {
            // 次のガソリンスタンドまで行けない時は行けるようになるまで給油する
            while (a[i] - now >= p) {
                if (que.empty()) {
                    std::cout << -1 << "\n";
                    return 0;
                }
                // std::cout << "here" << "\n";
                p += que.top(); que.pop();
                ans++;
            }
        }

        p-=a[i]-now; // 進んだ分だけガソリンを減らす
        now = a[i]; // nowをi番目のガソスタまですすめる
        que.push(b[i]); // queにi番目のガソスタのガソリン量を追加する
    }

    std::cout << ans << "\n";
    return 0;
}
