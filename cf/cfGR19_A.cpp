#include<bits/stdc++.h>
using namespace std;
const int inf = 0x7fffffff;
const int maxn = 100000 + 10;
int T;
int n;
int a[maxn];
int pre[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		pre[1] = a[1];
		for (int i = 2; i <= n; i++)
		pre[i] = max(pre[i - 1], a[i]);
		bool ans = false;
		int suf_mn = inf;
		for (int i = n; i >= 2; i--)
		{
			suf_mn = min(suf_mn, a[i]);
			if (pre[i - 1] > suf_mn)
			{
				ans = true;
				break;
			}
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}

