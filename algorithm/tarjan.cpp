#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
typedef long long ll;
int n, m;
vector<int> e[maxn << 1];
int val[maxn << 1];
int id[maxn], dfn[maxn], low[maxn], tim, cnt;
int dp[maxn << 1], indeg[maxn << 1];
bool ins[maxn];
queue<int> q;
stack<int> s; 
void tarjan(int x)
{
	dfn[x] = low[x] = ++tim;
	s.push(x);
	ins[x] = true;
	for (auto y : e[x])
	{
		if (!dfn[y])
		{
			tarjan(y);
			low[x] = min(low[x], low[y]);
		}
		else if (ins[y])
			low[x] = min(low[x], dfn[y]);
	}
	if (low[x] == dfn[x])
	{
		cnt++;
		int y = s.top();
		while (y != x)
		{
			id[y] = cnt;
			ins[y] = false;
			s.pop();
			y = s.top();
		}
		id[y] = cnt;
		ins[y] = false;
		s.pop();
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &val[i]);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
	}
	for (int i = 1; i <= n; i++)
		if (!dfn[i])
			tarjan(i);
	for (int x = 1; x <= n; x++)
	{
		val[id[x] + n] += val[x];
		for (auto y : e[x])
		{
			if (id[x] != id[y])
			{
				e[id[x] + n].push_back(id[y] + n);
				indeg[id[y] + n]++;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
		if (!indeg[i + n])
			q.push(i + n), dp[i + n] = val[i + n];
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (auto y : e[x])
		{
			dp[y] = max(dp[y], dp[x] + val[y]);
			indeg[y]--;
			if (!indeg[y])
				q.push(y);
		}
	}
	int ans = 0;
	for (int i = 1; i <= cnt; i++)
		ans = max(ans, dp[i + n]);
	printf("%d\n", ans);
}
