#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int maxq = 1000000 + 10;
int n, m, q;
set<pii> edge;
int ans[maxq], cnt;
int qry[maxq][3], len;
int fa[maxn], siz[maxn], mn[maxn];
int getfa(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void Union(int x, int y)
{
	int fx = getfa(x), fy = getfa(y);
	if (fx != fy)
	{
		fa[fx] = fy;
		siz[fy] += siz[fx];
		mn[fy] = min(mn[fy], mn[fx]);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
		siz[i] = 1;
		scanf("%d", mn + i);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (u > v) swap(u, v);
		edge.insert({u, v});
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			if (u > v) swap(u, v);
			if (edge.find({u, v}) != edge.end())
			{
				edge.erase({u, v});
				len++;
				qry[len][0] = op;
				qry[len][1] = u;
				qry[len][2] = v;
			}
		}
		else
		{
			int x;
			scanf("%d", &x);
			len++;
			qry[len][0] = op;
			qry[len][1] = x;
		}
	}
	for (auto x : edge)
		Union(x.first, x.second);
	for (int i = len; i >= 1; i--)
	{
		if (qry[i][0] == 1)
			Union(qry[i][1], qry[i][2]);
		else if (qry[i][0] == 2)
			ans[++cnt] = mn[getfa(qry[i][1])];
		else
			ans[++cnt] = siz[getfa(qry[i][1])];
	}
	for (int i = cnt; i >= 1; i--)
		printf("%d\n", ans[i]);
	return 0;
}

