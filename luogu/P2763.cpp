#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1100 + 10;
const int maxm = 22000 + 10;
struct node{
	int st, ed;
	int flow;
	int nxt;
}edge[maxm * 2];
int n, m, k;
int net_s, net_t;
int head[maxn], cur_head[maxn], tot;
int dep[maxn];
queue<int> q;
void add_edge(int st, int ed, int flow)
{
	tot++;
	edge[tot].st = st;
	edge[tot].ed = ed;
	edge[tot].flow = flow;
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

int dfs(int x, int f)
{
	int res = 0;
	if (x == net_t || f == 0) return f;
	for (int i = cur_head[x]; i != -1; i = edge[i].nxt)
	{
		int y = edge[i].ed;
		cur_head[x] = i;
		if (edge[i].flow > 0 && dep[y] == dep[x] + 1)
		{
			int tmp = dfs(y, min(edge[i].flow, f));
			res += tmp, f -= tmp;
			edge[i].flow -= tmp;
			edge[i^1].flow += tmp;
			if(f==0) break;
		}
	}
	if (res == 0) dep[x] = 0;
	return res;
}

vector<int> res[25];
void getedge()
{
	int num;
	scanf("%d%d", &k, &num);
	net_s = num + k + 1;
	n = net_t = net_s + 1;
	tot = -1;
	for (int i = 1; i <= n; i++)
		head[i] = -1;
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		m += x;
		add_edge(i, net_t, x);
		add_edge(net_t, i, 0);
	}
	for (int i = 1; i <= num; i++)
	{
		add_edge(net_s, k + i, 1);
		add_edge(k + i, net_s, 0);
		int x;
		scanf("%d", &x);
		while (x--)
		{
			int y;
			scanf("%d", &y);
			add_edge(k + i, y, 1);
			add_edge(y, k + i, 0);
		}
	}
} 

void solve_dinic()
{
	getedge();
	int ans = 0;
	while (bfs()) ans += dfs(net_s, INF);
	int sum = 0;
	for (int i = head[net_s]; i != -1; i = edge[i].nxt)
	{
		int v = edge[i].ed;
		if (!edge[i].flow)
		{
			sum++;
			for (int j = head[v]; j != -1; j = edge[j].nxt)
			{
				if (!edge[j].flow)
				{
					res[edge[j].ed].push_back(v - k);
					break;
				}
			}
		}
	}
	if (m == sum)
	{
		for (int i = 1; i <= k; i++)
		{
			printf("%d:", i);
			for (auto x : res[i])
				printf(" %d", x);
			puts("");
		}
	}
	else puts("No Solution!");
}
int main()
{
	solve_dinic();
	return 0;
}
