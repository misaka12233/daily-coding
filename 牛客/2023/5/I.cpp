#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
const int maxn = 200000 + 10;
int n;
int a[maxn];
ll sum[maxn], valid[maxn], f[4][31][maxn];
ll add(ll x, ll y)
{
	return (x + y) % mod;
}
ll sub(ll x, ll y)
{
	return (x - y + mod) % mod;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 0; i < n; i++)
		f[0][30][i] = 1;
	for (int k = 1; k <= 3; k++)
	{
		for (int b = 0, p = 1; b < 30; b++, p = p * 2)
		{
			for (int i = 1; i <= n; i++)
			{
				sum[i] = add(sum[i - 1], f[k - 1][30][i - 1]);
				if ((a[i] & p) > 0)
					valid[i] = sub(sum[i], valid[i - 1]);
				else
					valid[i] = valid[i - 1];
				f[k][b][i] = add(f[k][b][i - 1], valid[i] * p % mod);
				f[k][30][i] = add(f[k][30][i], f[k][b][i]);
			}
		}
	}
	printf("%lld\n", f[3][30][n]);
	return 0;
}

