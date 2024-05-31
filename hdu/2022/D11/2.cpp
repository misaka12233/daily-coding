#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n, k1, k2;
ll p;
ll a[maxn];
char ans[maxn];
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	 	scanf("%lld", a + i);
	scanf("%d%d%lld", &k1, &k2, &p);
	ll sum1 = 0, sum2 = 0;
	for (int i = k2 - 1; i >= 1; i--)
	{
		printf("0");
		sum2 += a[i];
		if (i >= k2 - k1 + 1) sum1 += a[i];
	}
	sum1 += a[k2];
	sum2 += a[k2];
	if (sum1 * k2 * 100 < sum2 * p * k1) printf("1");
	else printf("0");
	for (int i = k2 + 1; i <= n; i++)
	{
		sum1 += a[i], sum1 -= a[i - k1];
		sum2 += a[i], sum2 -= a[i - k2];
		if (sum1 * k2 * 100 < sum2 * p * k1) printf("1");
		else printf("0");
	}
	puts("");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

