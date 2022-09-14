#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 10;
const int maxm = 10000 + 10;
struct node{
	int st, ed;
	int flow;
	int nxt;
}edge[maxm * 2];
int n, m;
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

int cnt[maxn];
vector<pii> todo;
bool solve_dinic()
{
	int num, m1, m2;
	scanf("%d%d%d", &num, &m1, &m2);
	for (int i = 1; i <= num; i++) cnt[i] = 0;
	todo.clear();
	for (int i = 0; i < m1; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		if (z) cnt[x]++;
		else cnt[y]++;
	}
	for (int i = 0; i < m2; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == 1 || y == 1) cnt[1]++; 
		else todo.push_back({x, y});
	}
	net_s = num + todo.size() + 1;
	n = net_t = net_s + 1;
	tot = -1;
	for (int i = 1; i <= n; i++)
		head[i] = -1;
	for (int i = 0; i < todo.size(); i++)
	{
		add_edge(n + i + 1, todo[i].first, 1);
		add_edge(todo[i].first, n + i + 1, 0);
		add_edge(n + i + 1, todo[i].second, 1);
		add_edge(todo[i].second, n + i + 1, 0);
		add_edge(net_s, n + i + 1, 1);
		add_edge(n + i + 1, net_s, 0);
	}
	for (int i = 2; i <= num; i++)
	{
		if (cnt[i] > cnt[1])
			return false;
		add_edge(i, net_t, cnt[1] - cnt[i]);
		add_edge(net_t, i, 0);
	}
	int ans = 0;
	while (bfs()) ans += dfs(net_s, INF);
	return (ans == todo.size());
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		if (solve_dinic()) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
2
4 2 2
2 3 1
2 4 1
1 2
3 4
4 2 1
2 3 1
3 2 1
1 4
*/
