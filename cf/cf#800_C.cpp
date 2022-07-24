#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, m;
struct node{
	int ed;
	int nxt;
}edge[maxn];
int head[maxn], tot;
void add(int x, int y)
{
	tot++;
	edge[tot].ed = y;
	edge[tot].nxt = head[x];
	head[x] = tot;
}
int dis[maxn], cnt[maxn];
bool vis[maxn];
priority_queue<pii> q;
void dij()
{
	for (int i = 1; i <= n; i++)
		dis[i] = inf;
	dis[n] = 0;
	q.push(pii(0, n));
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].ed;
			cnt[v]--;
		}
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].ed;
			if (dis[v] > dis[u] + 1 + cnt[v])
			{
				dis[v] = dis[u] + 1 + cnt[v];
				q.push(pii(-dis[v], v));
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		cnt[x]++;
		add(y, x);
	}
	dij();
	printf("%d\n", dis[1]);
	return 0;
}

