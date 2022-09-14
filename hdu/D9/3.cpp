#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, q;
int a[maxn];
int sta[maxn], top;
int f[maxn][18], g[maxn][18];
void sol()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	a[++n] = inf;
	top = 1;
	sta[top] = n;
	f[n][0] = n;
	g[n][0] = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		while (top > 0 && a[i] > a[sta[top]]) top--;
		f[i][0] = sta[top];
		if (f[i][0] == i + 1) g[i][0] = 0;
		else g[i][0] = 1;
		sta[++top] = i;
	}
	for (int k = 1; k <= 17; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			f[i][k] = f[f[i][k - 1]][k - 1];
			g[i][k] = g[i][k - 1] + g[f[i][k - 1]][k - 1];
		}
	}
	while (q--)
	{
		int l, r, ans = 0;
		scanf("%d%d", &l, &r);
		if (l != r)
		{
			for (int i = 17; i >= 0; i--)
				if (f[l][i] < r)
					ans += g[l][i], l = f[l][i];
			ans += g[l][0];
			printf("%d\n", ans);
		}
		else puts("0");
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

