#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
typedef long long ll;
int n;
ll a[maxn];
void sol()
{
	scanf("%d", &n);
	ll ans, sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", a + i);
		sum += a[i];
	}
	ans = sum;
	sum -= a[1];
	for (int i = 2; i <= n; i++)
	{
		ans += max(0ll, sum);
		sum -= a[i];
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

