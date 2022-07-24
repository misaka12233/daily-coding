#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
struct node{
	int st;
	int ed;
	int nxt;
}edge[maxn << 1];
int head[maxn], tot;
void add(int x, int y)
{
	tot++;
	edge[tot].st = x;
	edge[tot].ed = y;
	edge[tot].nxt = head[x];
	head[x] = tot;
}
int rt, dp[maxn], deg[maxn];
bool vis[maxn];
void dfs(int x, int fa)
{
	int cnt = 0;
	for (int i = head[x]; i; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		if (y == fa) continue;
		dfs(y, x);
		dp[x] += dp[y];
		if (!vis[y]) cnt++;
		else vis[x] = true;
	}
	if (cnt > 1)
	{
		dp[x] += cnt - 1;
		vis[x] = true;
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		tot = rt = 0;
		for (int i = 1; i <= n; i++)
		{
			head[i] = 0;
			dp[i] = 0;
			deg[i] = 0;
			vis[i] = false;
		}
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
			deg[x]++;
			deg[y]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (deg[i] >= 3)
			{
				rt = i;
				break;
			}
		}
		if (n == 1) puts("0");
		else if (rt == 0) puts("1");
		else
		{
			dfs(rt, 0);
			printf("%d\n", dp[rt]);
		}
	}
	return 0;
}

