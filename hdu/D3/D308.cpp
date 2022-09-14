#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
struct node{
	ll x1, y1, z1;
	ll x2, y2, z2;
};
node p[maxn];
ll x[maxn], y[maxn], z[maxn];
int getcnt(int i, int j, int k)
{
	ll a1 = x[j] - x[i], b1 = y[j] - y[i], c1 = z[j] - z[i];
	ll a2 = x[k] - x[i], b2 = y[k] - y[i], c2 = z[k] - z[i];
	ll A = b1 * c2 - b2 * c1;
	ll B = a2 * c1 - a1 * c2;
	ll C = a1 * b2 - a2 * b1;
	ll D = - (A * x[i] + B * y[i] + C * z[i]);
	if (A == 0 && B == 0 && C == 0)
		return 0;
	int res = 0;
	for (int i = 1; i <= n; i++)
		if ((A * p[i].x1 + B * p[i].y1 + C * p[i].z1 + D) * (A * p[i].x2 + B * p[i].y2 + C * p[i].z2 + D) <= 0)
			res++;
	return res;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ll stx, sty, stz;
		ll a1, b1, c1;
		a1 = b1 = c1 = inf;
		bool share_line = true;
		int m = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld%lld%lld", &p[i].x1, &p[i].y1, &p[i].z1);
			m++;
			x[m] = p[i].x1;
			y[m] = p[i].y1;
			z[m] = p[i].z1;
			scanf("%lld%lld%lld", &p[i].x2, &p[i].y2, &p[i].z2);
			m++;
			x[m] = p[i].x2;
			y[m] = p[i].y2;
			z[m] = p[i].z2;
			if (a1 == inf)
			{
				a1 = p[i].x1 - p[i].x2;
				b1 = p[i].y1 - p[i].y2;
				c1 = p[i].z1 - p[i].z2;
				stx = p[i].x2;
				sty = p[i].y2;
				stz = p[i].z2;
			}
			else
			{
				ll a2, b2, c2, A, B, C;
				a2 = p[i].x1 - stx;
				b2 = p[i].y1 - sty;
				c2 = p[i].z1 - stz;
				A = b1 * c2 - b2 * c1;
				B = a2 * c1 - a1 * c2;
				C = a1 * b2 - a2 * b1;
				if (A != 0 || B != 0 || C != 0)
					share_line = false;
				a2 = p[i].x2 - stx;
				b2 = p[i].y2 - sty;
				c2 = p[i].z2 - stz;
				A = b1 * c2 - b2 * c1;
				B = a2 * c1 - a1 * c2;
				C = a1 * b2 - a2 * b1;
				if (A != 0 || B != 0 || C != 0)
					share_line = false;
			}
		}
		if (share_line)
		{
			printf("%d\n", n);
			continue;
		}
		int ans = 0;
		for (int i = 1; i <= m; i++)
			for (int j = i + 1; j <= m; j++)
				for (int k = j + 1; k <= m; k++)
					ans = max(ans, getcnt(i, j, k));
		printf("%d\n", ans);
	}
	return 0;
}

