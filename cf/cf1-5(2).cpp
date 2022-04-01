#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>

const int MAX_N = 45, MAX_V = 2000005, INF = 0x3f3f3f3f;

int a[MAX_N], n, m;
int cnt[MAX_V], vern = 0;
bool ver[MAX_V];

inline bool chkmx(int &a, int b) { return (a < b)? (a = b, 1): 0; }

inline void inc(int x){
	if (!ver[x]) ver[x] = true, cnt[x] = 1;
	else ++cnt[x];
}

int decompose(int x) {
	int ans = 1;
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			inc(i);
			if (cnt[i] == m) chkmx(ans, i);
			if (i != x / i) {
				inc(x / i);
				if (cnt[x / i] == m) chkmx(ans, x / i);
			}
		}
	}
	return ans;
}

int chk(){
	m = n >> 1;
	memset(ver,0,sizeof(ver));
	for (int i = 1; i <= n; ++i) m -= a[i] == a[vern];
	if (m <= 0) return INF;
	int ans = 1;
	for (int i = 1; i <= n; ++i) chkmx(ans, decompose(abs(a[i] - a[vern])));
	return ans;
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		int ans = 1;
		for (vern = 1; vern <= n; ++vern) chkmx(ans, chk());
		printf("%d\n", ans != INF ? ans : -1);
	}
	return 0;
}
