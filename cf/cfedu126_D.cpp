#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
int n;
ll k;
ll b[maxn];
ll c[maxn];
int lowbit(int x){return x & -x;}
void add(int x, ll v)
{
	for (int i = x; i <= n; i += lowbit(i))
		c[i] += v;
}
ll query(int x)
{
	ll res = 0;
	for (int i = x; i; i -= lowbit(i))
		res += c[i];
	return res;
}
int main()
{
	scanf("%d%lld", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", b + i);
	ll sum = 0, ans = 0;
	for (int i = n; i >= k; i--)
	{
		ll res = b[i] - sum;
		sum -= query(i);
		if (res > 0)
		{
			ll cnt = (res + k - 1) / k;
			add(i - k + 1, cnt);
			ans += cnt;
			sum += (k - 1) * cnt;
		}
	}
	for (ll i = k - 1; i >= 1; i--)
	{
		ll res = b[i] - sum;
		sum -= query(i);
		if (res > 0)
		{
			ll cnt = (res + i - 1) / i;
			add(1, cnt);
			ans += cnt;
			sum += (i - 1) * cnt;
		}
	}
	printf("%lld\n", ans);
	return 0;
}

