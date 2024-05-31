#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
ll fac[maxn];
ll C(int n, int m) { return fac[n] / fac[m] / fac[n - m]; }
ll gcd(ll x, ll y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main()
{
	scanf("%d", &n);
	fac[0] = 1;
	for (int i = 1; i <= 2 * n; i++)
		fac[i] = fac[i - 1] * i;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
	{
		ll lst = 1;
		for (int j = 1; j * i <= n; j++)
		{
			lst = lst * C(n - (j - 1) * i, i);
			sum = sum + lst;
		}
	}
	ll p = sum * fac[n];
	ll q = 1;
	for (int i = 1; i <= n; i++)
		q = q * C(2 * n - (i - 1) * 2, 2);
	ll g = gcd(p, q);
	printf("%lld/%lld\n", p / g, q / g);
	return 0;
}

