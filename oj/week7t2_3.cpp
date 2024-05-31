#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
const int mod = 998244353;
int n, tot[2];
int siz[maxn][2];
int ans;
struct node{
	int v;
	int w;
	int nxt;
};
node edge[maxn << 1];
int head[maxn], m;
void add(int u, int v, int w)
{
	m++;
	edge[m].v = v;
	edge[m].w = w;
	edge[m].nxt = head[u];
	head[u] = m;
}
void dfs(int u, int fa)
{
	for (int i = head[u]; i; i = edge[i].nxt)
	{
		int v = edge[i].v;
		if (v == fa) continue;
		dfs(v, u);
		ans = (ans + 1ll * edge[i].w * siz[v][0] % mod * (tot[1] - siz[v][1]) % mod) % mod;
		ans = (ans + 1ll * edge[i].w * siz[v][1] % mod * (tot[0] - siz[v][0]) % mod) % mod;
		siz[u][0] += siz[v][0];
		siz[u][1] += siz[v][1];
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
		add(v, u, w);
	}
	for (int k = 0; k < 2; k++)
	{
		scanf("%d", &tot[k]);
		for (int i = 1; i <= tot[k]; i++)
		{
			int x;
			scanf("%d", &x);
			siz[x][k] = 1;
		}
	}
	dfs(1, 0);
	printf("%d\n", ans);
	return 0;
}

