#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
const double eps = 0.00000001;
int n, m;
struct node{
	int y;
	double v;
	int nxt;
};
node edge[maxn * 4];
int head[maxn], tot;
void add(int x, int y, double v)
{
	tot++;
	edge[tot].y = y;
	edge[tot].v = log(v);
	edge[tot].nxt = head[x];
	head[x] = tot;
}
double dis[maxn];
bool vis[maxn];
int cnt[maxn];
queue<int> q;
bool spfa(int s, double w)
{
	for (int i = 1; i <= n + 1; i++) 
	{
		dis[i] = -10000000;
		cnt[i] = 0;
		vis[i] = false;
	}
	while (!q.empty()) q.pop();
	dis[s] = 0;
	q.push(s);
	vis[s] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].y;
			if (dis[v] < dis[u] + edge[i].v + w)
			{
				dis[v] = dis[u] + edge[i].v + w;
				cnt[v]++;
				if (cnt[v] > n) return false;
				if (!vis[v])
				{
					q.push(v);
					vis[v] = true;
				}
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, v1, y, v2;
		scanf("%d%d%d%d", &v1, &x, &v2, &y);
		add(x, y, 1.0 * v2 / v1);
	}
	for (int i = 1; i <= n; i++)
		add(n + 1, i, 1.0);
	double l = 0, r = 1, mid;
	while (r - l > eps)
	{
		mid = (l + r) / 2.0;
		if (spfa(n + 1, log(mid))) l = mid;
		else r = mid;
	}
	printf("%.7f\n", l);
	return 0;
}
/*
5 7
2 1 3 2
2 2 1 1
2 3 3 2
2 2 1 3
1 3 1000 4
1 4 1000 5
1 5 1000 3
*/
