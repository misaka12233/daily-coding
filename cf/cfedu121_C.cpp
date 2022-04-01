#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
ll h[maxn], k[maxn];
ll ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		scanf("%lld", k + i);
		for (int i = 1; i <= n; i++)
		scanf("%lld", h + i);
		ll lsth = 0, lstk = k[n] + 1;
		ans = 0;
		for (int i = n; i >= 1; i--)
		{
			if (lsth - lstk + k[i] < h[i])
			{
				ans += (h[i] + 1) * h[i] / 2;
				if (lsth - lstk + k[i] > 0)
				{
					ans -= (lsth + 1) * lsth / 2;
					ans += (h[i] + 1 + h[i] + lstk - k[i]) * (lstk - k[i]) / 2;
					lsth = h[i] + lstk - k[i];
				}
				else lsth = h[i], lstk = k[i];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

