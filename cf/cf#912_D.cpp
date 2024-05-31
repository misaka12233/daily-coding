#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
typedef long long ll;
int n, q;
ll a[maxn];
ll b[maxn];
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	while (q--)
	{
		ll k, ans = 0;
		scanf("%lld", &k);
		for (int i = 1; i <= n; i++)
			b[i] = a[i];
		for (ll t = (1ll << 59); t > 0; t >>= 1)
		{
			ll s = 0;
			for (int i = 1; i <= n; i++)
			{
				if ((b[i]&t) == 0)
					s += t - b[i] % t;
				if (s > k)
					break;
			}
			if (s <= k)
			{
				k -= s;
				ans += t;
				for (int i = 1; i <= n; i++)
					if ((b[i]&t) == 0)
						b[i] += t - b[i] % t;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

