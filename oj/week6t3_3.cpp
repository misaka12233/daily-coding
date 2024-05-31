#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 10;
int n, m, lim, st, ed;
struct node{
	int v;
	int cnt;
	node(int v, int cnt): v(v), cnt(cnt) {}
	bool operator < (const node &x) const
	{
		return v < x.v;
	}
};
vector<node> e[maxn];
int dis[maxn], cnt[maxn];
bool vis[maxn];
queue<int> q;
void bfs()
{
	q.push(st);
	memset(dis, 0x3f, sizeof(dis));
	dis[st] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto now : e[u])
		{
			int v = now.v;
			if (dis[v] == inf)
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
}
bool check()
{
	while (!q.empty()) q.pop();
	vis[ed] = true;
	q.push(ed);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		if (dis[u] <= lim) return true;
		for (auto now : e[u])
		{
			int v = now.v;
			cnt[v] += now.cnt;
			if (!vis[v] && cnt[v] >= 2)
			{
				vis[v] = true;
				q.push(v);
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d%d%d", &n, &lim, &ed, &st, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(node(v, 0));
		e[v].push_back(node(u, 0));
	}
	for (int i = 1; i <= n; i++)
	{
		sort(e[i].begin(), e[i].end());
		int now = 0;
		for (int j = 0; j < e[i].size(); j++)
		{
			while (j + 1 < e[i].size() && e[i][j].v == e[i][j + 1].v)
			{
				e[i][now].cnt++;
				j++;
			}
			e[i][now].v = e[i][j].v;
			e[i][now].cnt++;
			now++;
		}
		while (e[i].size() > now)
			e[i].pop_back();
	}
	bfs();
	if (check()) puts("hywin");
	else puts("Rickkwin");
	return 0;
}
/*
4 1
1 4
4
1 2
1 2
2 3
4 3
*/
