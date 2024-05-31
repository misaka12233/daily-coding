#include<bits/stdc++.h>
using namespace std;
const int mod = 998244353;
typedef long long ll;
ll add(ll a, ll b) 
{
	return (a + b) % mod;
}
ll sub(ll a, ll b)
{
	return (a - b + mod) % mod;
}
ll mul(ll a, ll b)
{
	return a * b % mod;
}
ll qpow(ll a, ll b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	} 
	return res;
}

void sol()
{
	bool swap_first = false;
	ll x, y, d, c;
	scanf("%lld%lld%lld%lld", &x, &y, &d, &c);
	if (x / d > y / d)
	{
		x -= d;
		swap(x, y);
		swap_first = true;
	}
	ll p, k = 0;
	for (ll i = 1; x * i / d <= y / d - k; i = i * 2)
		k++;
	
	p = mul(c, qpow(100, mod - 2));
	
	ll res = mul(qpow(p, k), qpow(add(p, 1), mod - 2));
	
	printf("%lld\n", swap_first ? sub(1, res) : res);
}

int T;
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

