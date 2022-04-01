#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T;
struct node{
	int ed;
	int num;
	int nxt;
}edge[maxn << 1];
int head[maxn], tot;
void add(int x, int y, int num)
{
	tot++;
	edge[tot].ed = y;
	edge[tot].num = num;
	edge[tot].nxt = head[x];
	head[x] = tot;
}
int n;
int deg[maxn];
int ans[maxn];
bool chk;
void dfs(int x, int lst, int step)
{
	for (int i = head[x]; i ; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		if (y == lst) continue;
		ans[edge[i].num] = ((step & 1)? 2 : 3);
		dfs(y, x, step + 1);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		tot = 0;
		chk = true;
		for (int i = 1; i <= n; i++)
			head[i] = deg[i] = 0;
		for (int i = 1; i < n; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			add(x, y, i);
			add(y, x, i);
			deg[x]++;
			deg[y]++;
			if (deg[x] >= 3 || deg[y] >= 3)
				chk = false;
		}
		if (chk)
		{
			for (int i = 1; i <= n; i++)
			{
				if (deg[i] == 1)
				{
					dfs(i, 0, 1);
					break;
				}
			}
			for (int i = 1; i < n; i++)
				printf("%d ", ans[i]);
			puts("");
		}
		else puts("-1");
	}
	return 0;
}

