#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int T;
int n;
int a[maxn];
ll c, d, ans;
void sol()
{
	scanf("%d%lld%lld", &n, &c, &d);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	int m = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] != a[i - 1])
			a[++m] = a[i];
	ll res = c * (n - m);
	n = m;
	ans = c * n + d;
	for (int i = 1; i <= n; i++)
		ans = min(ans, d * (a[i] - i) + c * (n - i));
	printf("%lld\n", ans + res);
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

