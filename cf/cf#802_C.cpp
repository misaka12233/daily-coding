#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
long long a[maxn], pre[maxn], suf[maxn]; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		long long ans = 0;
		for (int i = 1; i <= n; i++)
			scanf("%lld", a + i), pre[i] = suf[i] = 0;
		for (int i = 2; i <= n; i++)
		{
			if (a[i] - a[i - 1] > 0)
				suf[i] = a[i] - a[i - 1];
			else if (a[i] - a[i - 1] < 0)
				pre[i - 1] = a[i - 1] - a[i];
			ans += abs(a[i] - a[i - 1]);
		}
		long long x = a[1];
		for (int i = 1; i <= n; i++)
			x -= pre[i];
		ans += abs(x);
		printf("%lld\n", ans);
	}
	return 0;
}

