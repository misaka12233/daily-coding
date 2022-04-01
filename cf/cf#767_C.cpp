#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
int a[maxn];
int ans[maxn], cnt;
int sum[maxn];
bool vis[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
		sum[i] = vis[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			sum[a[i]]++;
		}
		int mx = 0;
		for (int i = 0; i <= n; i++)
		{
			if (!sum[i])
			{
				mx = i;
				break;
			}
		}
		cnt = 0;
		int l = 0, r = 1, now = 0, nxt = mx;
		while (r <= n)
		{
			sum[a[r]]--;
			if (!sum[a[r]]) nxt = min(nxt, a[r]);
			vis[a[r]] = true;
			while (vis[now]) now++;
			if (now == mx)
			{
				ans[++cnt] = mx;
				mx = nxt;
				for (int i = l + 1; i <= r; i++)
				vis[a[i]] = false;
				now = 0;
				l = r;
			}
			r++;
		}
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; i++)
		printf("%d ", ans[i]);
		puts("");
	}
	return 0;
}

