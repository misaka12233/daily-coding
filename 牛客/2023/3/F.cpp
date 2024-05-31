#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int T;
int n, m;
int d[maxn];
queue<int> q;
vector<int> e[maxn];
int f[20][maxn], g[20][maxn];
void bfs()
{
	d[1] = 1;
	q.push(1);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto &v : e[u])
		{
			if (d[v] == 0)
			{
				d[v] = d[u] + 1;
				f[0][v] = u;
				q.push(v);
			}
		}
	}
}
int getlca(int x, int y)
{
	if (d[x] < d[y]) swap(x, y);
	for (int k = 19; k >= 0; k--)
		if (d[f[k][x]] >= d[y])
			x = f[k][x];
	if (x == y) return x;
	for (int k = 19; k >= 0; k--)
		if (f[k][x] != f[k][y])
			x = f[k][x], y = f[k][y];
	return f[0][x];
}
int getmin_g(int x, int y)
{
	int res = inf;
	for (int k = 19; k >= 0; k--)
		if (d[f[k][x]] >= d[y])
			res = min(res, g[k][x]), x = f[k][x];
	return res;
}
bool sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		d[i] = 0;
		g[0][i] = inf;
		e[i].clear();
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
	}
	bfs();
	for (int k = 1; k <= 19; k++)
		for (int i = 1; i <= n; i++)
			f[k][i] = f[k - 1][f[k - 1][i]];
	for (int u = 1; u <= n; u++)
	{
		for (auto &v : e[u])
		{
			if (d[u] >= d[v] && getlca(u, v) != v)
				return false;
		}
	}
	for (int u = 1; u <= n; u++)
	{
		for (auto &v : e[u])
		{
			if (d[u] + 1 == d[v] && f[0][v] != u)
				g[0][v] = min(g[0][v], d[getlca(u, v)]);
		}
	}
	for (int k = 1; k <= 19; k++)
		for (int i = 1; i <= n; i++)
			g[k][i] = min(g[k - 1][i], g[k - 1][f[k - 1][i]]);
	for (int u = 1; u <= n; u++)
	{
		for (auto &v : e[u])
		{
			if (d[u] > d[v] && getlca(u, v) == v)
			{
				if (getmin_g(u, v) < d[v])
					return false;
			}
		}
	}
	return true;
} 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		if (sol()) puts("Yes");
		else puts("No");
	}
	return 0;
}
/*
10
5 6
1 2
1 3
2 4
4 5
3 4
5 2

9 12
1 2
1 3
2 4
2 5
3 6 
3 7
4 8
4 9
3 4
3 5
7 3
8 2

7 8
1 2
1 7
2 3
3 4
4 5
5 6
7 3
6 2

7 8
1 2
1 7
2 3
3 4
4 5
5 6
7 3
6 3

9 10
1 2
1 7
2 3
7 8
3 4
8 9
4 5
5 6
9 5
6 2
*/
