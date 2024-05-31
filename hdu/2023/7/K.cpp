#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void sol()
{
	ll x, a, b, ans = 0;
	scanf("%lld%lld%lld", &x, &a, &b);
	while (x != 0)
	{
		ll mn = min((x + a) / 2, (ll)sqrt(x + b));
		if (mn < x - 1)
		{
			x = mn;
			ans++;
		}
		else
		{
			ans += x;
			x = 0;
		}
	}
	printf("%lld\n", ans);
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

