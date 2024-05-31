#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 200000 + 10;
int T;
int n, m;
priority_queue<pii> q;
vector<int> e[maxn];
int val[maxn];
int vis[maxn];
int cnt[maxn];
int add[maxn];
int startFrom(int s)
{
	while (!q.empty()) q.pop();
	q.push({0, s});
	int sum = 0;
	while (!q.empty())
	{
		int u = q.top().second;
		if (val[u] > sum) return sum;
		q.pop();
		if (vis[u] != 0) continue;
		sum++;
		cnt[s]++;
		vis[u] = s;
		for (auto v :e[u])
		{
			if (vis[v] == 0)
				q.push({-val[v], v});
			else if (vis[v] != s && add[vis[v]] != s)
			{
				sum += cnt[vis[v]];
				add[vis[v]] = s;
			}
		}
	}
	return sum;
}
bool sol()
{
	scanf("%d%d", &n, &m);
	while (!q.empty()) q.pop();
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", val + i);
		e[i].clear();
		vis[i] = 0;
		cnt[i] = 0;
		add[i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (val[i] == 0)
			ans = max(ans, startFrom(i));
	return ans == n;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		if (sol()) puts("YES");
		else puts("NO");
	}
	return 0;
}
/*
1
11 10
0 1 0 1 0 1 3 2 0 1 2
1 2
3 4
5 6
2 7
4 7
6 7
7 8
1 8
9 10
10 11
*/
