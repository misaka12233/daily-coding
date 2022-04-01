#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T;
int n;
ll a[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		ll ans = 0;
		bool chk = false;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", a + i);
			if (1 < i && i < n)
			{
				if (a[i] >= 2) chk = true;
				ans += a[i] + (a[i] & 1);
			}
		}
		if (n == 3 && a[2] % 2 == 1) chk = false;
		if (chk) printf("%lld\n", ans / 2);
		else puts("-1");
	}
	return 0;
}

