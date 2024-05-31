#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
typedef long long ll;
const ll mod = 1e9 + 7;
const ll inv2 = mod - mod / 2;
// f[i] : i 以前的聚合后向右能存活的概率
// f[i] = sum(f[j]*(1/2)^(j-i)) (i < j < 2 * i and j <= n)
// f[n] = 1
// g[i] : i 能存活的概率
// g[i] = f[i] * (1/2)^((i+1)/2) 
// g[n] = (1/2)^((n+1)/2 - 1)
// g[i] / (1/2)^((i+1)/2) = sum( g[j] / (1/2)^((j+1)/2) * (1/2)^(j-i) ) (i < j < 2 * i and j <= n)
// g[i] = 2^(i/2) * sum( g[j] * (1/2)^(j/2) ) (i < j < 2 * i and j <= n)
ll g[maxn], p2[maxn], q2[maxn], suf[maxn];
void sol()
{
	int n;
	scanf("%d", &n);
	g[n] = q2[(n + 1) / 2 - 1];
	suf[n] = g[n] * q2[n / 2] % mod;
	suf[n + 1] = 0;
	for (int i = n - 1; i >= 1; i--)
	{
		g[i] = p2[i / 2] * (suf[i + 1] - suf[min(2 * i, n + 1)] + mod) % mod;
		suf[i] = (suf[i + 1] + g[i] * q2[i / 2] % mod) % mod;
	}
	for (int i = 1; i <= n; i++)
		printf("%lld\n", g[i]);
}
int main()
{
	p2[0] = 1;
	q2[0] = 1;
	for (int i = 1; i <= 1000000; i++)
	{
		p2[i] = p2[i - 1] * 2 % mod;
		q2[i] = q2[i - 1] * inv2 % mod;
	}
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

