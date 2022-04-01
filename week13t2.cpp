#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
queue <int> q;
int indeg[maxn], nxt[maxn];
bool vis[maxn], ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ans = true;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			indeg[i] = vis[i] = 0;
		for (int i = 1; i <= n; i++)
		{
			int y;
			scanf("%d", &y);
			nxt[i] = y;
			indeg[y]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (!indeg[i])
				q.push(i);
		}
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			indeg[nxt[x]]--;
			if (!indeg[nxt[x]])
				q.push(nxt[x]);
		}
		for (int i = 1; i <= n; i++)
		{
			if (indeg[i] && !vis[i])
			{
				int x = i, siz = 0;
				while (!vis[x])
				{
					vis[x] = true;
					siz++;
					x = nxt[x];
				}
				if (siz > 2)
					ans = false;
			}
		}
		if (ans)
			puts("Y");
		else
			puts("N");
	}
	return 0;
}

