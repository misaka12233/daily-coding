#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1000000 + 10;
int n;
int f[maxn], g[maxn];
// f[n] = f[n-1] + f[n/2] + ... + f[n/k]
// g[n] = g[n-1] + f[n]
int main()
{
	scanf("%d", &n);
	if (n == 1)
		printf("1\n");
	else if (n == 2)
		printf("2\n");
	else
	{
		g[3] = 1;
		for (int i = 4; i <= n; i++)
		{
			f[i] = (f[i] + f[i - 1] + 1) % mod;
			g[i] = (g[i - 1] + f[i]) % mod;
			for (int j = 2 * (i - 1); j <= n; j += i - 1)
			{
				f[j] = (f[j] + f[i]) % mod;
				f[j + 1] = (f[j + 1] + f[i]) % mod;
				f[j + 2] = (f[j + 2] + f[i]) % mod;
			}
		}
		printf("%lld\n", 2ll * n * g[n] % mod);
	}
	return 0;
}

