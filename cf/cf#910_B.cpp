#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef long long ll;
int n;
ll a[maxn];
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	ll ans = 0;
	for (int i = n - 1; i > 0; i--)
	{
		if (a[i] > a[i + 1])
		{
			ans += (a[i] + a[i + 1] - 1) / a[i + 1] - 1;
			a[i] = a[i] / ((a[i] + a[i + 1] - 1) / a[i + 1]);
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

