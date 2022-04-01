#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10; 
const ll mod = 1000000007;
struct node{
	ll x, y;
}readin[maxn], lim[maxn];
bool cmp(node a, node b)
{
	if (a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}
ll n, m, k, ans, cnt;
ll fastpow(ll x, ll k)
{
	if (x == 0)
		return 0;
	ll res = 1;
	while (k > 0)
	{
		if (k & 1)
			res = res * x % mod;
		x = x * x % mod;
		k >>= 1;
	}
	return res;
}
int main()
{
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		scanf("%lld%lld", &readin[i].x, &readin[i].y);
	sort(readin + 1, readin + k + 1, cmp);
	for(int i = 1; i <= k; i++)
	{
		while (readin[i].x == readin[i + 1].x && readin[i].y == readin[i + 1].y && i + 1 <= k)
			i++;
		lim[++cnt] = readin[i];
	}
	ll lst = -1, sum = 0, now = 1;
	ans = 1;
	for (int i = 1; i <= cnt; i++)
	{
		ll x = lim[i].x, y = lim[i].y;
		if (lst != x)
		{
			ans = (ans * now % mod + mod) % mod;
			lst = x;
			sum++;
			now = (n * (n + 1) / 2) % mod;
		}
		now = (now - y + mod) % mod;
	}
	ans = (ans * now % mod + mod) % mod;
	ans = (ans * fastpow((n * (n + 1) / 2) % mod, m - sum)) % mod;
	printf("%lld\n", ans);
	return 0;
}

