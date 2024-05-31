#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m, q;
int a[maxn];
int p[maxn];
int sum[maxn], ans[maxn][2];
int getpos(int s)
{
	int l = 1, r = m, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		if (sum[mid] <= s) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	m = 1;
	p[1] = 1;
	for (int i = 2; i <= n; i++)
	{
		if (p[m] == 1)
			p[m]++;
		else
		{
			if (a[i - 1] >= a[i - 2] && a[i] >= a[i - 1])
				p[m]++;
			else if (a[i - 1] < a[i - 2] && a[i] < a[i - 1])
				p[m]++;
			else
				p[++m] = 1;
		}
	}
	for (int i = 1; i <= m; i++)
		sum[i] = sum[i - 1] + p[i];
	scanf("%d", &q);
	while (q--)
	{
		int x;
		scanf("%d", &x);
		if (ans[x][0] == 0)
		{
			int now = 0;
			while (now < n)
			{
				int st = getpos(now), t = 0;
				if (sum[st] - now == 1)
				{
					if (n - now <= 2)
					{
						ans[x][0]++;
						break;
					}
					if ((a[sum[st]] <= a[sum[st] + 1] && a[sum[st] + 1] <= a[sum[st] + 2]) 
					|| (a[sum[st]] > a[sum[st] + 1] && a[sum[st] + 1] > a[sum[st] + 2]))
						st++;
					else
						t = 1;
				}
				ans[x][0]++;
				ans[x][1] += max(0, min(n, now + x) - sum[st] - t);
				now = max(now + x, sum[st]);
			}
		}
		printf("%d %d\n", ans[x][0], ans[x][1]);
	}
	return 0;
}

