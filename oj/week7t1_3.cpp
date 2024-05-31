#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
const int maxm = 1000000 + 10;
typedef long long ll;
ll ans;
struct node{
	int u, v;
	ll w;
}e[maxm];
bool cmp(node x, node y)
{
	return x.w < y.w;
}
int n, m;
int fa[maxn];
int getfa(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ll w;
			scanf("%lld", &w);
			m++;
			e[m].u = min(i, j);
			e[m].v = max(i, j) + 1;
			e[m].w = w;
		}
	}
	sort(e + 1, e + m + 1, cmp);
	for (int i = 1; i <= n + 1; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		//printf("%d %d %lld ", e[i].u, e[i].v - 1, e[i].w);
		int fu = getfa(e[i].u), fv = getfa(e[i].v);
		if (fu != fv)
		{
			fa[fu] = fv;
			ans += e[i].w;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

