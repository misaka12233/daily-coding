#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef long long ll;
int n;
ll a[maxn], b[maxn];
ll gcd(ll x, ll y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", a + i, b + i);
	ll g = a[1] * b[1], l = b[1];
	int ans = 1;
	for (int i = 2; i <= n; i++)
	{
		g = gcd(g, a[i] * b[i]);
		l = l * b[i] / gcd(l, b[i]);
		if (g % l != 0)
		{
			ans++;
			g = a[i] * b[i];
			l = b[i];
		}
	}
	printf("%d\n", ans);
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

