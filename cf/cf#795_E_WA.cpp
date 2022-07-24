#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
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
int fa[maxn]; 
int getfa(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
priority_queue<pii> q[2];
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
			fa[i] = i;
		}
		sort(val + 1, val + 2 * n + 1);
		sort(s + 1, s + n + 1, cmp);
		m = 0;
		for (int i = 1; i <= 2 * n; i++)
		{
			if (i + 1 <= 2 * n && val[i] == val[i + 1]) continue;
			val[++m] = val[i];
		}
		for (int k = 0; k <= 1; k++)
			while (!q[k].empty())
				q[k].pop();
		int now = 1;
		for (int i = 1; i <= m; i++)
		{
			while (s[now].l == val[i])
			{
				q[s[now].c].push(pii(-s[now].r, now));
				while (q[s[now].c ^ 1].size() > 1)
				{
					int u = q[s[now].c ^ 1].top().second;
					q[s[now].c ^ 1].pop();
					fa[getfa(u)] = getfa(now);
				}
				if (!q[s[now].c ^ 1].empty())
				{
					int u = q[s[now].c ^ 1].top().second;
					fa[getfa(u)] = getfa(now);
				}
				now++;
			}
			for (int k = 0; k <= 1; k++)
				while (!q[k].empty() && -q[k].top().first == val[i])
					q[k].pop();
		}
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (fa[i] == i)
				cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}

