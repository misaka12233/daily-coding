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
		int mx = 0, mn = inf, x;
		for (int i = 1; i <= n; i++)
		scanf("%d", &x), mx = max(mx, x), mn = min(mn, x);
		printf("%d\n", mx - mn);
	}
	return 0;
}

