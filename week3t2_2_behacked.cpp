#pragma warning(disable: 4996)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll NUM = 2e6 + 10, MOD = 998244353;
int lst[NUM], res[NUM];
int N;
bool exist[NUM] = {};
void read(int& x) {
	x = 0;
	char ch = 0;
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + (ch ^ '0');
		ch = getchar();
	}
}
int gcd(int x, int y)
{
	if (x > y) swap(x, y);
	while (x) {
		y %= x;
		if (x > y) swap(x, y);
	}
	return y;
}
int main()
{
	freopen("hack.in", "r", stdin);
	double st = clock(), ed;
	int T, temp, cnt, mem; read(T);
	ll ans = 1;
	while (T--) {
		mem = -1;
		read(N);
		for (int i = 1; i <= N; ++i)
			read(lst[i]);
		for (int i = 1; i <= N; ++i) {
			cnt = 0;
			if (!exist[i]) {
				temp = i;
				do {
					temp = lst[temp];
					exist[temp] = 1, ++cnt;
				} while (temp != i);
				for (int j = 0; j <= mem; ++j)
					cnt = cnt / gcd(cnt, res[j]);
				if (cnt > 1)
					res[++mem] = cnt;
			}
		}
		ans = 1;
		for (int i = 0; i <= mem; ++i)
			ans = ans * res[i] % MOD;
		memset(exist, 0, (N + 1) * sizeof(bool));
		printf("%lld\n", ans);
	}
	ed = clock();
	printf("%lf\n", ed - st);
	return 0;
}
