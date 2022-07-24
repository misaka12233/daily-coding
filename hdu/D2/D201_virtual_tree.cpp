#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n, q;
vector<int> ch[maxn];
int f[maxn][20];
int dep[maxn], dfn[maxn], tim;
void getdep(int x, int d)
{
	dep[x] = d;
	dfn[x] = tim++;
	for (auto y : ch[x])
		getdep(y, d + 1);
}
void getf()
{
	for (int k = 1; k <= 19; k++)
		for (int i = 1; i <= n; i++)
			f[i][k] = f[f[i][k - 1]][k - 1];
}
int LCA(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int k = 19; k >= 0; k--)
	{
		if (dep[f[x][k]] >= dep[y])
			x = f[x][k];
	}
	if (x == y) return x;
	for (int k = 19; k >= 0; k--)
	{
		if (f[x][k] != f[y][k])
		{
			x = f[x][k];
			y = f[y][k];
		}
	}
	return f[x][0];
}

int node[maxn], tot;
bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}
int sta[maxn], top;
struct virTr{
	virTr(int y, int cnt)
	{
		this->y = y;
		this->cnt = cnt;
	}
	int y;
	int cnt;
};
vector<virTr> edge[maxn];
bool tag[maxn][3];
int dp[maxn], ans;
void dfs(int x, bool up)
{
	dp[x] = 0;
	for (auto now : edge[x])
	{
		int y = now.y;
		dfs(y, up || tag[x][2]);
		dp[x] += dp[y];
		if (tag[y][0] && tag[y][1])
			dp[x] += now.cnt;
		tag[x][0] = tag[x][0] || tag[y][0];
		tag[x][1] = tag[x][1] || tag[y][1];
		tag[y][0] = tag[y][1] = tag[y][2] = false;
	}
	if (tag[x][0] && tag[x][1]) dp[x]++;
	if (!up && tag[x][2]) ans += dp[x];
	edge[x].clear();
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++)
			ch[i].clear();
		tim = 0;
		for (int i = 2; i <= n; i++)
		{
			scanf("%d", &f[i][0]);
			ch[f[i][0]].push_back(i);
		}
		getdep(1, 1);
		getf();
		while (q--)
		{
			tot = 0;
			int k[3];
			for (int i = 0; i < 3; i++)
				scanf("%d", k + i);
			for (int i = 0; i < 3; i++)
			{
				for (int j = 1; j <= k[i]; j++)
				{
					tot++;
					scanf("%d", &node[tot]);
					tag[node[tot]][i] = true;
				}
			}
			sort(node + 1, node + tot + 1, cmp);
			top = 0;
			sta[++top] = 1;
			for (int i = 1; i <= tot; i++)
			{
				if (!top)
					sta[++top] = node[i];
				else
				{
					int lca = LCA(sta[top], node[i]);
					while (top > 1 && dep[lca] < dep[sta[top - 1]])
					{
						edge[sta[top - 1]].push_back(virTr(sta[top], dep[sta[top]] - dep[sta[top - 1]] - 1));
						top--;
					}
					if (dep[lca] < dep[sta[top]])
					{
						edge[lca].push_back(virTr(sta[top], dep[sta[top]] - dep[lca] - 1));
						top--;
					}
					if (!top || sta[top] != lca) sta[++top] = lca;
					if (!top || sta[top] != node[i]) sta[++top] = node[i];
				}
			}
			while (top > 1)
			{
				edge[sta[top - 1]].push_back(virTr(sta[top], dep[sta[top]] - dep[sta[top - 1]] - 1));
				top--;
			}
			ans = 0;
			dfs(1, false);
			tag[1][0] = tag[1][1] = tag[1][2] = false;
			printf("%d\n", ans);
		}
	}
	return 0;
}
/*
1
9 5
1 1 2 3 4 4 5 5
2 2 2
6 8
7 9
4 3
*/
