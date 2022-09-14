#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
int main()
{
	scanf("%d", &n);
	ll now = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int k = 0;
		for (ll p = 1; p < n; k++, p = p * 10)
		{
			ll tmp = p * now % n;
			int l = tmp;
			int r = (tmp + p - 1 + n) % n;
			if (l <= r)
			{
				if (l <= i % n && i % n <= r)
					break;
			}
			else
			{
				if (i % n <= r || l <= i % n)
					break;
			}
		}
		ans += k;
		now = i;
	}
	printf("%d\n", ans);
	return 0;
}

