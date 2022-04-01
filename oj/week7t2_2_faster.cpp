#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int mod = 998244353;
int T;
int ans = 0;
int f[maxn];
int main()
{
	scanf("%d", &T);
	f[1] = 1;
	for (int i = 2; i <= 1e5; i++)
	{
		f[i] = i;
		int t = sqrt(i);
		for (int j = 2; j <= t; j++)
			(f[i] += f[i / j]) %= mod;
		int lst = i, now;
		for (int j = 1; j <= t; j++)
		{
			now = max(i / (j + 1), t);
			if (lst == now) break;
			(f[i] += 1ll * (lst - now) * f[j] % mod) %= mod;
			lst = now;
		}
	}
	while (T--)
	{
		int index;
		scanf("%d", &index);
		if (index >= 0) printf("%d\n", f[index]);
		else printf("%d\n", index);
	}
	return 0;
}

