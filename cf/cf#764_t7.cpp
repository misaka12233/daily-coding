#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n, m;
int fa[maxn], siz[maxn];
int pow2[50];
int ans;
struct node{
	int u, v, w;
}edge[maxn];
int getfa(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
bool check(int x)
{
	for (int i = 1; i <= n; i++)
		fa[i] = i, siz[i] = 1;
	for (int i = 1; i <= m; i++)
	{
		if ((x & edge[i].w) == edge[i].w)
		{
			int fu = getfa(edge[i].u), fv = getfa(edge[i].v);
			if (fu != fv)
			{
				fa[fu] = fv;
				siz[fv] += siz[fu];
			}
		}
	}
	int f = getfa(1);
	if (siz[f] == n) return true;
	else return false;
}
int main()
{
	pow2[0] = 1;
	for (int i = 1; i <= 30; i++) 
		pow2[i] = pow2[i - 1] << 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++)
			scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
		ans = 0x7fffffff;
		for (int i = 30; i >= 0; i--)
		{
			if (check(ans - pow2[i]))
				ans -= pow2[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}

