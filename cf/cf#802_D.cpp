#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, q;
ll v[maxn], sum[maxn];
ll tim[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", v + i);
		sum[i] = sum[i - 1] + v[i];
	}
	for (ll i = 1; i <= n; i++)
		tim[i] = max(tim[i - 1], (sum[i] + i - 1) / i);
	for (ll i = 1; i <= n; i++)
		tim[i] = max(tim[i], (sum[n] + i - 1) / i);
	scanf("%d", &q);
	for (int i = 1; i <= q; i++)
	{
		ll t;
		scanf("%lld", &t);
		if (t < tim[n]) puts("-1");
		else
		{
			int l = 1, r = n, mid;
			while (l < r)
			{
				mid = l + r >> 1;
				if (tim[mid] <= t) r = mid;
				else l = mid + 1;
			}
			printf("%d\n", l);
		}
	}
	return 0;
}

