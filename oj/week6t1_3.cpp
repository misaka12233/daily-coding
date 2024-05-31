#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3200 + 10;
int n, k; 
int deg[maxn];
int sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", deg + i);
	for (int i = 1; i <= n; i++)
	{
		sort(deg + i, deg + n + 1, greater<int>());
		for (int j = i + 1; j <= n; j++)
			if (deg[i] > 0 && deg[j] > 0)
				deg[i]--, deg[j]--;
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] != 0)
			return 0;
	return 1;
}
int main()
{
	scanf("%d", &k);
	int ans = 0;
	while (k--) ans += sol();
	printf("%d\n", ans);
	return 0;
}

