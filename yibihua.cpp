#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int edge[maxn][maxn];
int deg[maxn];
int ans[maxn * maxn], cnt;
void dfs(int x)
{
	for (int i = 1; i <= 25; i++)
	{
		if (edge[x][i])
		{
			edge[x][i] = edge[i][x] = 0;
			dfs(i);
		}
	}
	ans[++cnt] = x;
}
int main()
{
	for (int i = 1; i <= 25; i++)
		for (int j = 1; j <= 25; j++)
			scanf("%d", &edge[i][j]), deg[i] += edge[i][j];
	for (int i = 1; i <= 25; i++)
	{
		if (deg[i] % 2 == 0)
		{
			dfs(i);
			break;
		}
	}
	for (int i = 1; i <= cnt; i++)
	printf("%d ", ans[i]);
	return 0;
}

