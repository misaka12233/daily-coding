#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int maxn = 800 + 10;
const int maxm = 330000 + 10;
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
	for (int i = 1; i <= n + m + 2; i++)
		dis[i] = INF, vis[i] = false;
	dis[net_s] = 0;
	q.push(net_s);
	vis[net_s] = true;
	for (int i = 1; i <= n + m + 2; i++)
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

char s[maxn];
void solve_dinic()
{
	scanf("%d%d", &n, &m);
	tot = -1;
	for (int i = 1; i <= n + m + 2; i++)
		head[i] = -1;
	net_s = n + m + 1;
	net_t = n + m + 2;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + 1);
		for (int j = 1; j <= m; j++)
		{
			if (s[j] == '1')
			{
				add_edge(i, n + j, 1, 0);
				add_edge(n + j, i, 0, 0);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		add_edge(n + m + 1, i, 1, 0);
		add_edge(i, n + m + 1, 0, 0);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			add_edge(n + i, n + m + 2, 1, j);
			add_edge(n + m + 2, n + i, 0, -j);
		}
	}
	int maxflow = 0;
	while (spfa())
	{
		for (int i = 1; i <= n + m + 2; i++)
			vis[i] = false;
		maxflow += dfs(net_s, INF);
	}
	if (maxflow != n) puts("-1");
	else
	{
		for (int x = 1; x <= n; x++)
		{
			int res = 0;
			for (int i = head[x]; i != -1; i = edge[i].nxt)
			{
				if (!edge[i].flow && edge[i].ed <= n + m)
				{
					printf("%d ", edge[i].ed - n);
					break;
				}
			}
		}                
		puts("");
	}
}
int main()
{
	solve_dinic();
	return 0;
}

