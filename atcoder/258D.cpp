#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
ll a[maxn], b[maxn];
ll n, t;
ll f[maxn];
int main()
{
	scanf("%lld%lld", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", a + i, b + i);
	ll ans = -1;
	for (ll i = 1; i <= min(n, t); i++)
	{
		f[i] = f[i - 1] + a[i] + b[i];
		if (ans == -1 || ans > f[i] + (t - i) * b[i])
			ans = f[i] + (t - i) * b[i];
	}
	printf("%lld\n", ans);
	return 0;
}

