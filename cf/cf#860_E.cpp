#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
int n;
bool f[maxn];
int a[maxn], g[maxn][2], ans[maxn], suf[maxn];
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	f[n + 1] = true;
	g[n + 1][0] = g[n + 1][1] = 0;
	suf[n + 1] = 0;
	for (int i = n; i >= 1; i--)
	{
		f[i] = false;
		g[i][0] = 0;
		g[i][1] = suf[i + 1] + 1;
		if (i + a[i] + 1 <= n + 1)
		{
			f[i] = f[i + a[i] + 1];
			if (f[i])
				g[i][0] = g[i + a[i] + 1][0] + 1;
			else
				g[i][0] = 0;
			g[i][1] = max(g[i][1], g[i + a[i] + 1][1] + 1);
		}
		suf[i] = max(g[i][0], suf[i + 1]);
		if (f[i + 1] && g[i + 1][0] == a[i])
			ans[i] = 0;
		else if (f[i + 1] || g[i + 1][1] >= a[i])
			ans[i] = 1;
		else
			ans[i] = 2;
	}
	for (int i = 1; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

