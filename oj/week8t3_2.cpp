#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
const int maxm = 2000000 + 10;
struct node{
	int st, ed;
	int nxt;
}edge[maxm << 1];
int n, m;
int head[maxn], tot, deg[maxn];
ll tim[maxn], ans[maxn];
bool vis[maxn];
queue<int> q;
void add(int x, int y)
{
	tot++;
	edge[tot].st = x;
	edge[tot].ed = y;
	edge[tot].nxt = head[x];
	head[x] = tot;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", tim + i);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		if (tim[u] != -1 && tim[v] != -1)
		{
			add(v, u);
			deg[u]++;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] == 0 && tim[i] != -1)
		{
			q.push(i);
			ans[i] = tim[i];
			vis[i] = true;
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = head[u]; i; i = edge[i].nxt)
		{
			int v = edge[i].ed;
			deg[v]--;
			ans[v] = max(ans[u] + tim[v], ans[v]);
			if (deg[v] == 0)
			{
				q.push(v);
				vis[v] = true;
			}
		}
	}
	ll max_ans = 0;
	bool chk = true;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] || tim[i] == -1)
			max_ans = max(ans[i], max_ans);
		else
		{
			chk = false;
			break;
		}
	}
	if (chk)
		printf("%lld\n", max_ans);
	else
		puts("bad idea");
	return 0;
}

