#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
typedef long long ll;
int n;
ll x[maxn], y[maxn];
bool check(ll ansx, ll ansy)
{
	if (abs(ansx) > 1e9 || abs(ansy) > 1e9)
		return false;
	for (int i = 1; i <= n; i++)
		if (ansx != x[i] && ansy != y[i] && abs(x[i] - ansx) != abs(y[i] - ansy))
			return false;
	return true;
}
bool inLine(ll A, ll B, ll C, ll &ansx, ll &ansy)
{
	for (int i = 2; i <= n; i++)
	{
		if (A * x[i] + B * y[i] + C != 0)
		{
			if (B != 0 && check(x[i], (-A * x[i] - C) / B))
			{
				ansx = x[i];
				ansy = (-A * x[i] - C) / B;
				return true;
			}
			if (A != 0 && check((-B * y[i] - C) / A, y[i]))
			{
				ansx = (-B * y[i] - C) / A;
				ansy = y[i];
				return true;
			}
			if (A+B != 0 && check((B * x[i] - B * y[i] - C) / (A + B), (A * y[i] - A * x[i] - C) / (A + B)))
			{
				ansx = (B * x[i] - B * y[i] - C) / (A + B);
				ansy = (A * y[i] - A * x[i] - C) / (A + B);
				return true;
			}
			if (A-B != 0 && check((-B * x[i] - B * y[i] - C) / (A - B), (A * y[i] + A * x[i] + C) / (A - B)))
			{
				ansx = (-B * x[i] - B * y[i] - C) / (A - B);
				ansy = (A * y[i] + A * x[i] + C) / (A - B);
				return true;
			}
			return false;
		}
	}
	ansx = x[1];
	ansy = y[1];
	return true;
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", x + i, y + i);
	if (n == 1)
	{
		printf("YES\n%lld %lld\n", x[1], y[1]);
		return;
	}
	ll ansx, ansy;
	if (inLine(1, 0, -x[1], ansx, ansy))
	{
		printf("YES\n%lld %lld\n", ansx, ansy);
		return;
	}
	if (inLine(0, 1, -y[1], ansx, ansy))
	{
		printf("YES\n%lld %lld\n", ansx, ansy);
		return;
	}
	if (inLine(1,-1, -x[1]+y[1], ansx, ansy))
	{
		printf("YES\n%lld %lld\n", ansx, ansy);
		return;
	}
	if (inLine(1, 1, -x[1]-y[1], ansx, ansy))
	{
		printf("YES\n%lld %lld\n", ansx, ansy);
		return;
	}
	printf("NO\n");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

