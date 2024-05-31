#include<bits/stdc++.h>
using namespace std;
const int maxn = 150000 + 10;
typedef long long ll;
const ll inf = 1ll * 0x3f3f3f3f * maxn;
int n;
ll a[maxn];
ll getans(int k)
{
	ll mn = inf, mx = 0;
	for (int i = 1; i <= n; i += k)
	{
		ll r = 0;
		for (int j = 0; j < k; j++)
			r += a[i + j];
		mn = min(mn, r);
		mx = max(mx, r);
	}
	return mx - mn;
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	ll ans = 0;
	for (int i = 1; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			ans = max(ans, getans(i));
			ans = max(ans, getans(n / i));
		}
	}
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

