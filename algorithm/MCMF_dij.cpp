#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x7fffffff;
const int maxn = 5000 + 10;
const int maxm = 50000 + 10;
struct node{
	int st, ed;
	int flow;
	int nxt;
	int cost;
}edge[maxm * 2];
int n, m;
int net_s, net_t;
int head[maxn], tot;
int dis[maxn], pre[maxn], lst[maxn], flow[maxn], exd[maxn];
bool vis[maxn];
priority_queue<pii> q;
void add_edge(int st, int ed, int flow, int cost)
{
	tot++;
	edge[tot].st = st;
	edge[tot].ed = ed;
	edge[tot].flow = flow;
	edge[tot].cost = cost;
	edge[tot].nxt = head[st];
	head[st] = tot;
}

bool dij()
{
	for (int i = 1; i <= n; i++)
	{
		exd[i] += dis[i];
		dis[i] = flow[i] = INF;
		vis[i] = false;
	}
	dis[net_s] = 0;
	q.push({0, net_s});
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			int v = edge[i].ed;
			if (edge[i].flow > 0 && dis[v] > dis[u] + edge[i].cost + exd[u] - exd[v])
			{
				dis[v] = dis[u] + edge[i].cost + exd[u] - exd[v];
				pre[v] = u;
				lst[v] = i;
				flow[v] = min(flow[u], edge[i].flow);
				q.push({-dis[v], v});
			}
		}
	}
	return dis[net_t] != INF;
}

int maxflow, mincost;
void MCMF()
{
	maxflow = mincost = 0;
	while (dij())
	{
		maxflow += flow[net_t];
		mincost += flow[net_t] * (dis[net_t] - exd[net_s] + exd[net_t]);
		int now = net_t;
		while (now != net_s)
		{
			edge[lst[now]].flow -= flow[net_t];
			edge[lst[now]^1].flow += flow[net_t];
			now = pre[now];
		}
	}
}

void solve_dinic()
{
	scanf("%d%d%d%d", &n, &m, &net_s, &net_t);
	tot = -1;
	for (int i = 1; i <= n; i++)
		head[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y, f, c;
		scanf("%d%d%d%d", &x, &y, &f, &c);
		add_edge(x, y, f, c);
		add_edge(y, x, 0, -c);
	}
	MCMF();
	printf("%d %d\n", maxflow, mincost);
}
int main()
{
	solve_dinic();
	return 0;
}

