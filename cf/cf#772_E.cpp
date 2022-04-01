#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, m;
struct node{
	int st, ed;
	int nxt;
	int type;
}edge[maxn << 1];
int dir[maxn], head[maxn], tot;
int deg[maxn];
int ans[maxn], cnt;
queue<int> q;
void add(int type, int x, int y)
{
	tot++;
	edge[tot].st = x;
	edge[tot].ed = y;
	edge[tot].nxt = head[x];
	edge[tot].type = type;
	head[x] = tot;
}
bool dfs(int x, int now)
{
	dir[x] = now;
	for (int i = head[x]; i; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		if (dir[y] == now) return false;
		if (dir[y] != 0) continue;
		if (!dfs(y, 3 - now)) return false;
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		add(type, x, y);
		add(type, y, x);
	}
	for (int i = 1; i <= n; i++)
	{
		if (dir[i]) continue;
		if (!dfs(i, 1))
		{
			puts("NO");
			return 0;
		}
	}
	for (int i = 1; i <= tot; i += 2)
	{
		if (edge[i].type == dir[edge[i].st])
			deg[edge[i].ed]++;
		else
			deg[edge[i].st]++;
	}
	for (int i = 1; i <= n; i++)
		if (!deg[i])
			q.push(i), ans[i] = ++cnt;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = edge[i].nxt)
		{
			int y = edge[i].ed;
			if (edge[i].type == dir[x])
			{
				deg[y]--;
				if (deg[y] == 0)
				{
					q.push(y);
					ans[y] = ++cnt;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == 0)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		if (dir[i] == 1)
			printf("L ");
		else
			printf("R ");
		printf("%d\n", ans[i]);
	}
	return 0;
}

