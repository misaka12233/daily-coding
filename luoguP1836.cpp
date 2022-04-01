#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll f(ll x)
{
	if (x < 10)
		return (x + 1) * x / 2;
	ll a = x / 10, b = x % 10, ans = 0;
	ll tmp = a, sum = 0;
	while (tmp)
	{
		sum += tmp % 10;
		tmp /= 10;
	}
	ans += (b + 1) * sum;
	ans += (b + 1) * b / 2;
	ans += a * 45;
	ans += 10 * f(a - 1);
	return ans;
}
void sol1()
{
	printf("%lld\n", f(n));
}
void sol2()
{
	ll now = n, ans = 0, cnt = 1;
	while (now)
	{
		ll x = now % 10;
		now /= 10;
		ans += cnt * now * 45;
		ans += cnt * (x - 1) * x / 2;
		ans += (n % cnt + 1) * x;
		cnt *= 10;
	}
	printf("%lld\n", ans);
}
int main()
{
	scanf("%d", &n);
	//sol1();
	sol2();
	return 0;
}

