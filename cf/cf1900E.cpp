#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
const int inf = 0x3f3f3f3f;
typedef long long ll;
int n, m;
vector<int> e[maxn << 1];
ll val[maxn << 1];
int siz[maxn << 1];
int id[maxn], dfn[maxn], low[maxn], tim, cnt;
int f[maxn << 1], indeg[maxn << 1];
ll g[maxn << 1];
bool ins[maxn];
queue<int> q;
stack<int> s; 
void tarjan(int x)
{
	dfn[x] = low[x] = ++tim;
	s.push(x);
	ins[x] = true;
	for (auto y : e[x])
	{
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (ins[y])
			low[x] = min(low[x], dfn[y]);
	}
	if (low[x] == dfn[x])
	{
		cnt++;
		int y = s.top();
		while (y != x)
		{
			id[y] = cnt;
			ins[y] = false;
			s.pop();
			y = s.top();
		}
		id[y] = cnt;
		ins[y] = false;
		s.pop();
	}
}
void sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &val[i]);
		e[i].clear();
		e[i + n].clear();
		dfn[i] = 0;
		val[i + n] = siz[i + n] = indeg[i + n] = 0;
	}
	tim = cnt = 0;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int x = 1; x <= n; x++)
	{
		val[id[x] + n] += val[x];
		siz[id[x] + n]++;
		for (auto y : e[x])
		{
			if (id[x] != id[y])
			{
				e[id[x] + n].push_back(id[y] + n);
				indeg[id[y] + n]++;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		f[i + n] = siz[i + n];
		g[i + n] = val[i + n];
		if (!indeg[i + n])
			q.push(i + n);
	}
	int mxlen = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		mxlen = max(mxlen, f[x]);
		for (auto y : e[x])
		{
			if (f[y] < f[x] + siz[y])
			{
				f[y] = f[x] + siz[y];
				g[y] = g[x] + val[y];
			}
			if (f[y] == f[x] + siz[y])
				g[y] = min(g[y], g[x] + val[y]);
			indeg[y]--;
			if (!indeg[y])
				q.push(y);
		}
	}
	ll ans = 1ll * inf * n;
	for (int i = 1; i <= cnt; i++)
		if (f[i + n] == mxlen)
			ans = min(ans, g[i + n]);
	printf("%d %lld\n", mxlen, ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}
