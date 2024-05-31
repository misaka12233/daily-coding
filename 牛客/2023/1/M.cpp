#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll exgcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll gcd = exgcd(b, a % b, y, x);
	y = y - a / b * x;
	//printf("%d*%d + %d*%d = %d\n", x, a, y, b, gcd);
	return gcd;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		ll a, b, s, x, y, gcd, ans, tmp, p;
		scanf("%lld%lld%lld", &a, &b, &s);
		gcd = exgcd(a, b, x, y);
		if (s % gcd == 0)
		{
			p = s / gcd;
			x = x * p;
			y = y * p;
			ans = (abs(x) + abs(y)) * 2;
			if (x > 0)
			{
				tmp = x / (b / gcd);
				x = x % (b / gcd);
				y = y + tmp * (a / gcd);
				if (y >= 0)
				{
					ans = min(ans, (x + y) * 2);
					x -= b / gcd;
					y += a / gcd;
					ans = min(ans, (y - x) * 2 - 1);
					x += b / gcd;
					y -= a / gcd;
					tmp = y / (a / gcd);
					y = y % (a / gcd);
					x = x + tmp * (b / gcd);
					ans = min(ans, (x + y) * 2);
					x += b / gcd;
					y -= a / gcd;
					ans = min(ans, (x - y) * 2 - 1);
				}
				else
				{
					ans = min(ans, (x - y) * 2 - 1);
					x -= b / gcd;
					y += a / gcd;
					ans = min(ans, (y - x) * 2 - 1);
				}
			}
			else
			{
				tmp = y / (a / gcd);
				y = y % (a / gcd);
				x = x + tmp * (b / gcd);
				if (x >= 0)
				{
					ans = min(ans, (x + y) * 2);
					x += b / gcd;
					y -= a / gcd;
					ans = min(ans, (x - y) * 2 - 1);
					x -= b / gcd;
					y += a / gcd;
					tmp = x / (b / gcd);
					x = x % (b / gcd);
					y = y + tmp * (a / gcd);
					ans = min(ans, (x + y) * 2);
					x -= b / gcd;
					y += a / gcd;
					ans = min(ans, (y - x) * 2 - 1);
				}
				else
				{
					ans = min(ans, (y - x) * 2 - 1);
					x += b / gcd;
					y -= a / gcd;
					ans = min(ans, (x - y) * 2 - 1);
				}
			}
			printf("%lld\n", ans);
		}
		else puts("-1");
	}
	return 0;
}

