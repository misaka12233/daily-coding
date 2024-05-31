#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n, m;
int fa[maxn], siz[maxn][2], r[maxn];
int getfa(int x)
{
	if (x == fa[x]) return x;
	int fx = getfa(fa[x]);
	r[x] ^= r[fa[x]];
	return fa[x] = fx;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
		siz[i][0] = 1;
		siz[i][1] = r[i] = 0;
	}
	int ans = n;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int fx = getfa(x), fy = getfa(y);
		if (fx == fy)
		{
			if (r[x] == r[y]) printf("0 ");
			else printf("1 ");
		}
		else
		{
			ans -= max(siz[fx][0], siz[fx][1]);
			ans -= max(siz[fy][0], siz[fy][1]);
			r[fx] = r[x] ^ r[y] ^ 1;
			fa[fx] = fy;
			siz[fy][0] += siz[fx][r[fx] ^ 0];
			siz[fy][1] += siz[fx][r[fx] ^ 1];
			ans += max(siz[fy][0], siz[fy][1]);
			printf("1 ");
		}
		printf("%d\n", ans);
	}
	return 0;
}

