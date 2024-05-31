#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
int n;
int a[maxn];
int cnt[maxn];
int dp[maxn];
void sol()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		cnt[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (a[i] < n)
			cnt[a[i]]++;
	}
	int m = 0;
	for (int i = 0; i < n; i++)
	{
		if (cnt[i] != 0)
			m++;
		else
			break;
	}
	for (int i = 1; i <= m; i++)
	{
		dp[i] = inf;
		for (int j = 0; j < i; j++)
			dp[i] = min(dp[i], dp[j] + i * (cnt[j] - 1) + j);
	}
	printf("%d\n", dp[m]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

