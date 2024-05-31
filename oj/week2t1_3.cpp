#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 10;
struct node{
	int u, v;
	ll w;
};
int n, m;
int fa[maxn];
node e[maxn];
bool cmp(node x, node y)
{
	return x.w < y.w;
}
int getfa(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++)
		scanf("%d%d%lld", &e[i].u, &e[i].v, &e[i].w);
	sort(e + 1, e + m + 1, cmp);
	ll ans = 0;
	for (int i = 1; i <= m; i++)
	{
		int fu = getfa(e[i].u), fv = getfa(e[i].v);
		if (e[i].w <= 0)
		{
			ans += e[i].w;
			if (fu != fv)
				fa[fu] = fv;
		}
		else if (fu != fv)
		{
			ans += e[i].w;
			fa[fu] = fv;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

