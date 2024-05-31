#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
struct node{
	int c;
	int l, r;
}s[maxn];
bool cmp(node x, node y)
{
	return x.l < y.l;
}
int T;
int n;
int val[maxn << 1], m;
int cnt[2][maxn << 1], sum[2][maxn << 1];
int getpos(int x)
{
	int l = 1, r = m, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		if (val[mid] == x) return mid;
		if (val[mid] < x) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d%d", &s[i].c, &s[i].l, &s[i].r);
			val[2 * i - 1] = s[i].l;
			val[2 * i] = s[i].r;
		}
		val[2 * n + 1] = -1;
		sort(val + 1, val + 2 * n + 2);
		sort(s + 1, s + n + 1, cmp);
		m = 0;
		for (int i = 1; i <= 2 * n + 1; i++)
		{
			cnt[0][i] = cnt[1][i] = sum[0][i] = sum[1][i] = 0;
			if (i + 1 <= 2 * n + 1 && val[i] == val[i + 1]) continue;
			val[++m] = val[i];
		}
		for (int i = 1; i <= n; i++)
		{
			cnt[s[i].c][getpos(s[i].l)]++;
			cnt[s[i].c][getpos(s[i].r) + 1]--;
		}
		for (int i = 1; i <= m; i++)
		{
			cnt[0][i] += cnt[0][i - 1];
			sum[0][i] = sum[0][i - 1] + cnt[0][i];
			cnt[1][i] += cnt[1][i - 1];
			sum[1][i] = sum[1][i - 1] + cnt[1][i];
		}
		int ans = 0, ed[2];
		ed[0] = ed[1] = -1;
		for (int i = 1; i <= n; i++)
		{
			if (s[i].l > ed[s[i].c ^ 1])
			{
				if (!(s[i].l <= ed[s[i].c] && sum[s[i].c ^ 1][getpos(min(ed[s[i].c], s[i].r))] - sum[s[i].c ^ 1][getpos(s[i].l) - 1] > 0))
					ans++;
			}
			ed[s[i].c] = max(ed[s[i].c], s[i].r);
		}
		printf("%d\n", ans);
	}
	return 0;
}
