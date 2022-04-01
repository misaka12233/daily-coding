#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
ll a[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
		if (a[n] >= 0)
		{
			if (a[n - 1] > a[n]) puts("-1");
			else
			{
				printf("%d\n", n - 2);
				for (int i = n - 2; i >= 1; i--)
				printf("%d %d %d\n", i, i + 1, n);
			}
		}
		else
		{
			bool ans = true;
			for (int i = 1; i < n; i++)
				ans = ans && (a[i] <= a[i + 1]);
			if (!ans) puts("-1");
			else puts("0");
		}
	}
	return 0;
}

