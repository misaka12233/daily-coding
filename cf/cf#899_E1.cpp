#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2500 + 10;
int n, m;
int a[maxn], b[maxn];
int ans[2][maxn << 2];
int sol(int *p, int l, int *res)
{
	int cnt = 0;
	for (int i = 1; i <= l; i++)
	{
		if (p[i] == i) continue;
		for (int j = i + 1; j <= l; j++)
		{
			if (p[j] == i)
			{
				res[++cnt] = i;
				res[++cnt] = j - i;
				res[++cnt] = l - j + 1;
				swap(p[i], p[j]);
				break;
			}
		}
	}
	return cnt;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	int cnt[2];
	cnt[0] = sol(a, n, ans[0]);
	cnt[1] = sol(b, m, ans[1]);
	if (!((cnt[0] - cnt[1]) & 1) || (n & 1) || (m & 1))
	{
		int mx;
		if ((cnt[0] - cnt[1]) & 1)
		{
			if (n & 1)
			{
				for (int i = 1; i <= n; i++)
					ans[0][cnt[0] + i] = 1;
				cnt[0] += n;
			}
			else
			{
				for (int i = 1; i <= m; i++)
					ans[1][cnt[1] + i] = 1;
				cnt[1] += m;
			}
		}
		if (cnt[0] > cnt[1])
			mx = 0;
		else
			mx = 1;
		for (int i = cnt[mx ^ 1] + 1; i <= cnt[mx]; i++)
		{
			if (i & 1)
				ans[mx ^ 1][i] = 1;
			else
				ans[mx ^ 1][i] = (mx == 0) ? m : n;
		}
		printf("%d\n", cnt[mx]);
		for (int i = 1; i <= cnt[mx]; i++)
			printf("%d %d\n", ans[0][i], ans[1][i]);
	}
	else puts("-1");
	return 0;
}
/*
A x B y C
i
B y C x A
j - i
C x A y B
l - j + 1
A y B x C
*/
