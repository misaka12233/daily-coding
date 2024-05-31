#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 10;
struct node{
	int v;
	int nxt;
};
node edge[maxn << 2];
int head[maxn], tot;
void add(int u, int v)
{
	tot++;
	edge[tot].v = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
}

int n, m, k;
int g, w;
int dis[110][maxn];
queue<int> q;
void bfs(int st, int rk)
{
	for (int i = 1; i <= n; i++)
		dis[rk][i] = inf;
	dis[rk][st] = 0;
	q.push(st);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].v, d = dis[rk][u] + 1;
			if (dis[rk][v] > d)
			{
				dis[rk][v] = d;
				q.push(v);
			}
		}
	}
}

int final[maxn];
int ans[maxn][1010];
int get_id(int u, int c)
{
	return u * (k + 1) + c;
}
int getans()
{
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= k; j++)
			ans[i][j] = inf;
	ans[1][0] = final[1] == 0;
	q.push(get_id(1, 0));
	while (!q.empty())
	{
		int u = q.front() / (k + 1), c = q.front() % (k + 1);
		q.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].v, d = ans[u][c] + 1;
			int c_v = c + (d >= final[v]);
			if (c_v > k) continue;
			if (ans[v][c_v] > d)
			{
				ans[v][c_v] = d;
				q.push(get_id(v, c_v));
				if (v == n)
					return d;
			}
		}
	}
	return inf;
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	scanf("%d%d", &g, &w);
	for (int i = 1; i <= g; i++)
	{
		int u;
		scanf("%d", &u);
		bfs(u, w + i);
	}
	for (int i = 1; i <= w; i++)
	{
		int u;
		scanf("%d", &u);
		bfs(u, i);
	}
	for (int i = 1; i <= n; i++)
	{
		int mn1, mn2;
		mn1 = mn2 = inf;
		for (int j = 1; j <= w; j++)
			mn1 = min(mn1, dis[j][i]);
		for (int j = 1; j <= g; j++)
			mn2 = min(mn2, dis[w + j][i]);
		if (mn1 <= mn2) final[i] = inf;
		else final[i] = mn2;
	}
	int res = getans();
	if (res != inf)
	{
		puts("yes");
		printf("%d\n", res);
	}
	else puts("no");
	return 0;
}

