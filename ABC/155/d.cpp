#pragma GCC optimize ("O3")
#pragma GCC target ("avx")
//#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

const int cm = 1 << 17;
char cn[cm], * ci = cn + cm, ct;
inline char getcha() {
	if (ci - cn == cm) { fread_unlocked(cn, 1, cm, stdin); ci = cn; }
	return *ci++;
}
inline int getint() {
	int A = 0;
	int pn = 1;
	if (ci - cn + 16 > cm) {
		if ((ct = getcha()) == '-') { pn = -1; ct = getcha(); }
		A = ct - '0';
		while ((ct = getcha()) >= '0') A = A * 10 + ct - '0';;
		return pn * A;
	}
	else {
		if ((ct = *ci++) == '-') { pn = -1; ct = *ci++; }
		A = ct - '0';
		while ((ct = *ci++) >= '0') A = A * 10 + ct - '0';;
		return pn * A;
	}
}
void pakuri_sort(int N, int A[]) {
	const int b = 8;
	int tmp[200001];
	rep(k, 4) {
		int kazu[1 << b] = {}, kazu2[1 << b] = {};
		rep(i, N) kazu[A[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu[i + 1] += kazu[i];
		for (int i = N - 1; i >= 0; i--) tmp[--kazu[A[i] >> k * b & ((1 << b) - 1)]] = A[i];
		k++;
		rep(i, N) kazu2[tmp[i] >> k * b & ((1 << b) - 1)]++;
		rep(i, (1 << b) - 1) kazu2[i + 1] += kazu2[i];
		for (int i = N - 1; i >= 0; i--) A[--kazu2[tmp[i] >> k * b & ((1 << b) - 1)]] = tmp[i];
	}
}

int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = getint();
	ll K = 0;
	while ((ct = *ci++) >= '0') K = K * 10 + ct - '0';

	int A[200000];
	int *sei = A, *fu = A + 199999;
	int zero = 0;
	rep(i, N) {
		int a = getint();
		if (a > 0) *sei++ = a;
		else if (a < 0) *fu-- = -a;
		else zero++;
	}
	int seik = sei - A;
	int fuk = A + 199999 - fu;
	sei = A;
	fu++;
	pakuri_sort(seik, sei);
	pakuri_sort(fuk, fu);
	ll k0 = ll(seik) * fuk + ll(zero) * (zero - 1) / 2 + ll(zero) * (N - zero);

	ll L = -1000000000000000001, R = 1000000000000000000;
	while (L + 1 < R) {
		ll M = (L + R) / 2;
		ll k = 0;
		if (M >= 0) {
			k += k0;
			if (k >= K) { R = M; continue; }
			int i = 0;
			int j = seik - 1;
			while (i < seik) {
				while (j > i && ll(sei[i]) * sei[j] > M) j--;
				if (i == j) break;
				k += j - i;
				i++;
			}
			if (k >= K) { R = M; continue; }
			i = 0;
			j = fuk - 1;
			while (i < fuk) {
				while (j > i && ll(fu[i]) * fu[j] > M) j--;
				if (i == j) break;
				k += j - i;
				i++;
			}
		}
		else {
			int j = 0;
			rep(i, seik) {
				while (j < fuk && ll(sei[i]) * fu[fuk - j - 1] >= -M) j++;
				k += j;
			}
		}
		if (k >= K) R = M;
		else L = M;
	}

	printf("%lld\n", R);

	Would you please return 0;
}
