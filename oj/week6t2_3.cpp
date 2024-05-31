#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
struct node{
	int u, v, w;
};
int topo[maxn], deg[maxn];
vector<int> e[maxn];
node edge[maxn];
queue<int> q;
bool check(int val)
{
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n; i++)
	{
		topo[i] = deg[i] = 0;
		e[i].clear();
	}
	for (int i = 1; i <= m; i++)
	{
		if (edge[i].w > val)
		{
			deg[edge[i].v]++;
			e[edge[i].u].push_back(edge[i].v);
		}
	}
	int id = 0;
	for (int i = 1; i <= n; i++)
		if (deg[i] == 0)
			q.push(i);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		topo[u] = ++id;
		for (auto v : e[u])
		{
			deg[v]--;
			if (deg[v] == 0)
				q.push(v);
		}
	}
	for (int i = 1; i <= n; i++)
		if (topo[i] == 0)
			return false;
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	int l = 0, r = 1000000;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	check(l);
	for (int i = 1; i <= m; i++)
	{
		if (edge[i].w <= l && topo[edge[i].u] > topo[edge[i].v])
			swap(edge[i].u, edge[i].v);
		printf("%d %d\n", edge[i].u, edge[i].v);
	}
	return 0;
}

