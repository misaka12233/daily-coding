#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 10;
int n, m;
ll px[maxn], py[maxn];
ll sx[maxn], sy[maxn];
ll mul(ll x1, ll y1, ll x2, ll y2)
{
	return x1 * x2 + y1 * y2;
}
bool check(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	return (mul(x1 - x2, y1 - y2, x3 - x2, y3 - y2) > 0 && mul(x1 - x3, y1 - y3, x2 - x3, y2 - y3) > 0);
}
double dis(ll x1, ll y1, ll x2, ll y2)
{
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double linedis(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
	ll A = y2 - y3;
	ll B = x3 - x2;
	ll C = x2 * y3 - x3 * y2;
	return 1.0 * abs(A * x1 + B * y1 + C) / sqrt(A * A + B * B);
}
int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i++)
		scanf("%lld%lld", px + i, py + i);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", sx + i, sy + i);
	for (int i = 1; i <= n; i++)
	{
		double ans = dis(sx[i], sy[i], px[1], py[1]);
		for (int j = 2; j <= m; j++)
		{
			ans = min(ans, dis(sx[i], sy[i], px[j], py[j]));
			if (check(sx[i], sy[i], px[j - 1], py[j - 1], px[j], py[j]))
				ans = min(ans, linedis(sx[i], sy[i], px[j - 1], py[j - 1], px[j], py[j]));
		}
		printf("%.4f\n", ans);
	}
	return 0;
}

