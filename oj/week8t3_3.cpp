#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
const int maxm = 100000 + 10;
const int mod = 998246353;
int n, m;
int h[maxn];
int dp[maxn];
int deg[maxn];
queue<int> q;
struct node{
	int v;
	int nxt;
};
node edge[maxm];
int head[maxn], tot;
void add(int u, int v)
{
	tot++;
	edge[tot].v = v;
	edge[tot].nxt = head[u];
	head[u] = tot;
	deg[v]++;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", h + i);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (h[u] > h[v])
			add(u, v);
		else if (h[u] < h[v])
			add(v, u);
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		if (!deg[i])
			q.push(i);
	}
	int ans = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		ans = (ans + dp[u]) % mod;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].v;
			dp[v] = (dp[v] + dp[u]) % mod;
			deg[v]--;
			if(!deg[v]) q.push(v);
		}
	}
	printf("%d\n", ans);
	return 0;
}

