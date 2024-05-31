#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
typedef pair<pii, int> pid;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int maxm = 300000 + 10;
int T;
int n, m;
struct eee{
	int x, y;
	ll w, p;
};
eee edge[maxm];
struct node{
	int t;
	ll w, p;
	int nex;
};
node e[3][maxm];
int h[3][maxn], tot[3];

void add(int op, int x, int y, ll w, ll p)
{
	tot[op]++;
	e[op][tot[op]].t = y;
	e[op][tot[op]].w = w;
	e[op][tot[op]].p = p;
	e[op][tot[op]].nex = h[op][x];
	h[op][x] = tot[op];
}

int dfn[maxn], low[maxn], dfncnt, s[maxn], in_stack[maxn], tp;
int scc[maxn], sc;  // 结点 i 所在 SCC 的编号

void tarjan(int u) {
  low[u] = dfn[u] = ++dfncnt, s[++tp] = u, in_stack[u] = 1;
  for (int i = h[0][u]; i; i = e[0][i].nex) {
    const int &v = e[0][i].t;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stack[v]) {
      low[u] = min(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++sc;
    while (s[tp] != u) {
      scc[s[tp]] = sc;
      in_stack[s[tp]] = 0;
      --tp;
    }
    scc[s[tp]] = sc;
    in_stack[s[tp]] = 0;
    --tp;
  }
}

int indeg[maxn], topo[maxn], id;
bool inque[maxn];
queue<int> q1;
void toposort()
{
	for (int i = 1; i <= n; i++)
		if (indeg[scc[i]] == 0 && !inque[scc[i]])
			q1.push(scc[i]), inque[scc[i]] = true;
	while (!q1.empty())
	{
		int u = q1.front();
		topo[u] = ++id;
		q1.pop();
		for (int i = h[1][u]; i; i = e[1][i].nex)
		{
			int v = e[1][i].t;
			indeg[v]--;
			if (!indeg[v]) q1.push(v);
		}
	}
}

bool vis[maxn];
priority_queue<pid> q;
ll dis[maxn][2];
void dij()
{
	dis[scc[1]][0] = dis[scc[1]][0] = 0;
	q.push({{0, -topo[scc[1]]}, scc[1]});
	while (!q.empty())
	{
		int u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = h[2][u]; i; i = e[2][i].nex)
		{
			int v = e[2][i].t;
			if (dis[v][0] > dis[u][0] + e[2][i].w)
			{
				dis[v][0] = dis[u][0] + e[2][i].w;
				dis[v][1] = dis[u][1] + e[2][i].p;
				q.push({{-dis[v][0], -topo[v]}, v});
			}
			else if (dis[v][0] == dis[u][0] + e[2][i].w)
				dis[v][1] = max(dis[v][1], dis[u][1] + e[2][i].p);
		}
	}
}

void all_initial()
{
	dfncnt = tp = sc = id = 0;
	for (int k = 0; k < 3; k++)
	{
		tot[k] = 0;
		for (int i = 1; i <= n; i++)
			h[k][i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		in_stack[i] = indeg[i] = inque[i] = vis[i] = topo[i] = dfn[i] = 0;
		dis[i][0] = 1ll * inf * n;
		dis[i][1] = 0;
	}
	while (!q1.empty()) q1.pop();
	while (!q.empty()) q.pop();
}

void sol()
{
	
	scanf("%d%d", &n, &m);
	all_initial();
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%lld%lld", &edge[i].x, &edge[i].y, &edge[i].w, &edge[i].p);
		if (edge[i].w == 0)
			add(0, edge[i].x, edge[i].y, edge[i].w, edge[i].p);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int i = 1; i <= m; i++)
	{
		if (scc[edge[i].x] != scc[edge[i].y] && edge[i].w == 0)
		{
			add(1, scc[edge[i].x], scc[edge[i].y], edge[i].w, edge[i].p);
			indeg[scc[edge[i].y]]++;
		}
	}
	toposort();
	for (int i = 1; i <= m; i++)
		if (topo[scc[edge[i].x]] != 0 && topo[scc[edge[i].y]] != 0 && scc[edge[i].x] != scc[edge[i].y])
			add(2, scc[edge[i].x], scc[edge[i].y], edge[i].w, edge[i].p);
	dij();
	printf("%lld %lld\n", dis[scc[n]][0], dis[scc[n]][1]);
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		sol();
	}
	return 0;
}
/*
1
7 20
1 6 0 13
4 3 0 15
1 7 0 17
4 5 0 8
5 4 0 4
3 7 0 19
5 3 5 4
4 7 8 4
2 3 15 7
5 3 12 9
5 7 5 9
2 5 17 14
3 4 1 3
4 6 0 0
1 4 4 19
6 1 5 9
7 3 17 9
4 7 13 2
5 3 18 14
5 7 2 10
*/
