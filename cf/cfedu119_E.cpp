#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n, m, q;
int fa[maxn], fir[maxn];
int ans[maxn];
int getfa(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
int main()
{
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		int op, x, y;
		scanf("%d", &op);
		if (op == 1)
		{
			scanf("%d", &x);
			m = max(m, x);
			n++;
			if (!fir[x])
				fir[x] = n;
			fa[n] = fir[x];
		}
		else
		{
			scanf("%d%d", &x, &y);
			m = max(m, y);
			if (x != y)
			{
				if (!fir[y])
					fir[y] = fir[x];
				else
					fa[fir[x]] = fir[y];
				fir[x] = 0;
			}
		}
	}
	for (int i = 1; i <= m; i++)
		if (fir[i])
			ans[fir[i]] = i;
	for (int i = 1; i <= n; i++)
		printf("%d ",ans[getfa(i)]);
	return 0;
}

