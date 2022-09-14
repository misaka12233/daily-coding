#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int maxn = 5000 + 10;
const int maxm = 50000 + 10;
struct node{
	int st, ed;
	int flow;
	int cost;
	int nxt;
	int custom_num, site_num, type;
}edge[maxm * 2];
int n, m;
int net_s, net_t;
int head[maxn], cur_head[maxn], tot;
int dis[maxn];
bool vis[maxn];
queue<int> q;
void add_edge(int st, int ed, int flow, int cost)
{
	tot++;
	edge[tot].st = st;
	edge[tot].ed = ed;
	edge[tot].flow = flow;
	edge[tot].cost= cost;
	edge[tot].nxt = head[st];
	head[st] = tot;
}

bool spfa()
{
	for (int i = 1; i <= n; i++)
		dis[i] = INF, vis[i] = false;
	dis[net_s] = 0;
	q.push(net_s);
	vis[net_s] = true;
	for (int i = 1; i <= n; i++)
		cur_head[i] = head[i];
	while (!q.empty())
	{
		int u = q.front();
		vis[u] = false;
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			int v = edge[i].ed;
			if (edge[i].flow > 0 && dis[v] > dis[u] + edge[i].cost)
			{
				dis[v] = dis[u] + edge[i].cost;
				if (!vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	return dis[net_t] != INF;
}

int dfs(int x, int f)
{
	int res = 0;
	if (x == net_t || f == 0) return f;
	if (vis[x]) return 0;
	vis[x] = true;
	for (int i = cur_head[x]; i != -1; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		cur_head[x] = i;
		if (edge[i].flow > 0 && dis[y] == dis[x] + edge[i].cost)
		{
			int tmp = dfs(y, min(edge[i].flow, f));
			res += tmp, f -= tmp;
			edge[i].flow -= tmp;
			edge[i^1].flow += tmp;
			if(f==0) break;
		}
	}
	vis[x] = false;
	return res;
}

void solve_dinic()
{
	scanf("%d%d%d%d", &n, &m, &net_s, &net_t);
	tot = -1;
	for (int i = 1; i <= n; i++) head[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int u, v, f, c;
		scanf("%d%d%d%d", &u, &v, &f, &c);
		add_edge(u, v, f, c);
		add_edge(v, u, 0, -c);
	}
	int maxflow = 0, mincost = 0;
	while (spfa())
	{
		for (int i = 1; i <= n; i++)
			vis[i] = false;
		int f = dfs(net_s, INF);
		maxflow += f;
		mincost += dis[net_t] * f;
	}
	printf("%d %d\n", maxflow, mincost);
}
int main()
{
	solve_dinic();
	return 0;
}

