#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 80 + 10;
const int mod = 998244353;
int dp[maxn];
int n;
void addeq(int &a, int b)
{
	a += b;
	if(a > mod)
	a -= mod;
}
int mul(int a, int b){ return 1ll * a * b % mod; }
int main()
{
	scanf("%d", &n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			if (j >= i)
				addeq(dp[j], dp[j - i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		addeq(ans, mul(dp[i], n - i));
	printf("%d", ans);
	return 0;
}

