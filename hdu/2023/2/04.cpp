#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 10;
const ll mod = 998244353;
ll qpow(ll a, ll b) // a^b
{
	ll res = 1;
	while (b > 0)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		printf("%lld\n", (qpow(2, n - 1) - 1 + mod) % mod);
	}
	return 0;
}

