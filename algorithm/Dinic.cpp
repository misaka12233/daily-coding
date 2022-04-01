#include<bits/stdc++.h>
using namespace std;
const long long INF = 0x7fffffffffffff;
const int maxn = 200 + 10;
const int maxm = 5000 + 10;
struct node{
	int st, ed;
	long long flow;
	int nxt;
	int custom_num, site_num, type;
}edge[maxm * 2];
int n, m;
int net_s, net_t;
int head[maxn], cur_head[maxn], tot;
int dep[maxn];
queue<int> q;
void add_edge(int st, int ed, int flow, int custom_num, int site_num, int type)
{
	tot++;
	edge[tot].st = st;
	edge[tot].ed = ed;
	edge[tot].flow = flow;
	edge[tot].custom_num = custom_num;
	edge[tot].site_num = site_num;
	edge[tot].type = type;
	edge[tot].nxt = head[st];
	head[st] = tot;
}

bool bfs()
{
	for (int i = 1; i <= n; i++)
		dep[i] = 0;
	dep[net_s] = 1;
	q.push(net_s);
	for (int i = 1; i <= n; i++)
		cur_head[i] = head[i];
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i != -1; i = edge[i].nxt)
		{
			int v = edge[i].ed;
			if (edge[i].flow > 0 && !dep[v])
			{
				dep[v] = dep[u] + 1;
				q.push(v);
			}
		}
	}
	return dep[net_t] != 0;
}

long long dfs(int x, long long f)
{
	long long res = 0;
	if (x == net_t || f == 0) return f;
	for (int i = cur_head[x]; i != -1; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		cur_head[x] = i;
		if (edge[i].flow > 0 && dep[y] == dep[x] + 1)
		{
			long long tmp = dfs(y, min(edge[i].flow, f));
			res += tmp, f -= tmp;
			edge[i].flow -= tmp;
			edge[i^1].flow += tmp;
			if(f==0) break;
		}
	}
	return res;
}

void solve_dinic()
{
	scanf("%d%d%d%d", &n, &m, &net_s, &net_t);
	tot = -1;
	for (int i = 1; i <= n; i++)
		head[i] = -1;
	for (int i = 1; i <= m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		add_edge(x, y, z, 0, 0, 0);
		add_edge(y, x, 0, 0, 0, 0);
	}
	long long ans = 0;
	while (bfs()) ans += dfs(net_s, INF);
	printf("%lld\n", ans);
}
int main()
{
	solve_dinic();
	return 0;
}

