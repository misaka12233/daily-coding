#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
struct node{
	int to;
	int nxt;
}edge[maxn << 1];
int head[maxn], tot;
void add(int x, int y)
{
	tot++;
	edge[tot].to = y;
	edge[tot].nxt = head[x];
	head[x] = tot;
}
int siz[maxn];
int ans[maxn];
int n, c[maxn];
void dfs1(int x, int fa)
{
	siz[x] = c[x];
	ans[x] = c[x];
	for (int i = head[x]; i ; i = edge[i].nxt)
	{
		int y = edge[i].to;
		if (y == fa) continue;
		dfs1(y, x);
		siz[x] += siz[y];
		ans[x] |= c[y] | ((siz[y] >= 2) ? ans[y] : 0);
	}
}
void changeRoot(int x, int y)
{
	int tmp = siz[y];
	siz[y] = siz[x];
	siz[x] -= tmp;
	ans[y] |= c[x] | ((siz[x] >= 2) ? ans[x] : 0);
}
void dfs2(int x, int fa)
{
	for (int i = head[x]; i ; i = edge[i].nxt)
	{
		int y = edge[i].to;
		if (y == fa) continue;
		changeRoot(x, y);
		dfs2(y, x);
		changeRoot(y, x);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	scanf("%d", c + i);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 0);
	for (int i = 1; i <= n; i++)
	printf("%d ", ans[i]);
	puts("");
	return 0;
}

