#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0xfffffffffffffff;
const int maxn = 100000 + 10;
int T;
int n, m, k;
struct node{
	int to;
	int x, y;
	ll val;
	ll edval;
	int nxt;
}edge[maxn];
int head[maxn], tot;
ll x[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		tot = 0;
		for (int i = 1; i <= n; i++)
		{
			head[i] = 0;
			scanf("%lld", x + i);
		}
		for (int i = 1; i <= k; i++)
		{
			int a, b, c, d, h;
			scanf("%d%d%d%d%d", &c, &d, &a, &b, &h);
			tot++;
			edge[tot].to = b;
			edge[tot].x = c;
			edge[tot].y = d;
			edge[tot].val = h;
			edge[tot].nxt = head[a];
			edge[tot].edval = inf;
			head[a] = tot;
		}
		ll ans = inf;
		for (int i = 2; i <= n; i++)
		{
			for (int j = head[i]; j; j = edge[j].nxt)
			{
				ll tmp = inf;
				int from = edge[j].x;
				if (from != 1)
				{
					for (int l = head[from]; l; l = edge[l].nxt)
						tmp = min(tmp, edge[l].edval + x[from] * abs(edge[j].y - edge[l].to));
				}
				else tmp = x[1] * abs(edge[j].y - 1);
				if (tmp < inf)
				{
					tmp -= edge[j].val;
					edge[j].edval = tmp;
				}
				if (i == n)
					ans = min(ans, edge[j].edval + x[n] * abs(m - edge[j].to));
			}
		}
		if (ans >= inf)
			puts("NO ESCAPE");
		else
			printf("%lld\n", ans);
	}
	return 0;
}
