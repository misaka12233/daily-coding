#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
int a[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
		a[n + 1] = 0;
		int ans = 0;
		for (int i = 2; i < n; i++)
		{
			if (a[i] > a[i - 1] && a[i] > a[i + 1])
			{
				ans++;
				a[i + 1] = max(a[i], a[i + 2]);
			}
		}
		printf("%d\n", ans);
		for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
		puts("");
	}
	return 0;
}

