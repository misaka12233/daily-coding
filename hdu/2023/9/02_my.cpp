#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000000 + 10;
int f[maxn];
int cnt2, cnt3;
ll p2[100], p3[100];
int main()
{
	int T;
	scanf("%d", &T);
	int lim = 1000000;
	for (int i = 2; i <= lim; i++)
	{
		f[i] = lim;
		if (i % 2 == 0)
			f[i] = min(f[i], f[i / 2] + 1);
		if (i % 3 == 0)
			f[i] = min(f[i], f[i / 3] + 1);
		f[i] = min(f[i], f[i - 1] + 1);
	}
	ll mx = 1000000000000000000;
	p2[0] = p3[0] = 1;
	for (int i = 1; p2[i - 1] * 2 <= mx; i++)
		p2[i] = p2[i - 1] * 2, cnt2 = i;
	for (int i = 1; p3[i - 1] * 3 <= mx; i++)
		p3[i] = p3[i - 1] * 3, cnt3 = i;
	while (T--)
	{
		ll n;
		int ans = lim;
		scanf("%lld", &n);
		for (int i = 0, j = cnt3; i <= cnt2; i++)
		{
			while (p2[i] * p3[j] >= n) j--;
			ll x = n;
			int t2 = i, t3 = j, res = 0;
			while (t2 > 0 || t3 > 0)
			{
				int div2 = x % 2 + 1;
				int div3 = x % 3 + 1;
				if (t2 > 0 && t3 > 0)
				{
					if (div2 < div3)
						x /= 2, res += div2, t2--;
					else
						x /= 3, res += div3, t3--;
				}
				else if (t2 > 0)
					x /= 2, res += div2, t2--;
				else
					x /= 3, res += div3, t3--;
			}
			ans = min(ans, res + f[x]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

