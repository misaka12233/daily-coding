#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int n, m, e;
int vis[maxn], match[maxn];
vector<int> edge[maxn];
bool dfs(int x)
{
	vis[x] = true;
	for (auto y : edge[x])
	{
		if (match[y] != 0)
		{
			if (!vis[match[y]] && dfs(match[y]))
			{
				match[y] = x;
				return true;
			}
		}
		else
		{
			match[y] = x;
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d", &n, &m, &e);
	for (int i = 1; i <= e; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		edge[x].push_back(y);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < i; j++)
			vis[j] = false;
		if (dfs(i))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}

