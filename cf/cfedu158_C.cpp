#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
void sol()
{
	int n;
	int mx = 0, mn = inf;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		mx = max(mx, x);
		mn = min(mn, x);
	}
	int ans = 0;
	while (mx > mn)
	{
		mx = (mx + mn) / 2;
		ans++;
	}
	printf("%d\n", ans);
	if (ans <= n && ans != 0)
	{
		for (int i = 1; i <= ans; i++)
			printf("%d ", mn);
		printf("\n");
	}
} 
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

