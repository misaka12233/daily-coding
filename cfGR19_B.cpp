#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int ans = 0, x;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			ans += i * (n - i + 1);
			if (x == 0) ans += i * (n - i + 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}

