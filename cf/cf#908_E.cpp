#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int m;
int n[maxn];
vector<ll> a[maxn], c[maxn];
ll least[maxn], offset[maxn];
ll l[maxn], r[maxn], sum[maxn];
void sol()
{
	scanf("%d", &m);
	int cnt = 0;
	ll L = 0, R = 0;
	for (int i = 1; i <= m; i++)
	{
		sum[i] = 0;
		a[i].clear();
		c[i].clear();
		scanf("%d%lld%lld", n + i, l + i, r + i);
		L += l[i];
		R += r[i];
		cnt += n[i];
		for (int j = 0; j < n[i]; j++)
		{
			ll x;
			scanf("%lld", &x);
			a[i].push_back(x);
		}
		for (int j = 0; j < n[i]; j++)
		{
			ll x;
			scanf("%lld", &x);
			c[i].push_back(x);
			sum[i] += x;
		}
	}
	if (R - L + 1 > cnt)
	{
		puts("0");
		return;
	}
	for (int i = 0; i <= R - L; i++)
		least[i] = offset[i] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 0; j < n[i]; j++)
		{
			if (L <= a[i][j] && a[i][j] <= R)
			{
				ll t = sum[i] - c[i][j];
				if (t < l[i])
				{
					least[a[i][j] - L] += l[i] - t;
					t = l[i];
				}
				offset[a[i][j] - L] += max(0ll, r[i] - t);
			}
		}
	}
	ll ans = 1e18;
	for (int i = 0; i <= R - L; i++)
		ans = min(ans, least[i] + max(0ll, i + L + offset[i] - R));
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

