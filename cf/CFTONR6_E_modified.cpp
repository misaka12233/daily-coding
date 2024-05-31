
#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
int n;
int a[maxn];
int vis[maxn];
int dp[maxn][maxn];
int mex[maxn][maxn];
vector<int> l[maxn];
int sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), l[i].clear();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
			vis[j] = 0, dp[i][j] = 0;
		int now = 0;
		for (int j = i; j <= n; j++)
		{
			vis[a[j]] = 1;
			while (vis[now] == 1) now++;
			mex[i][j] = now;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
			if (mex[i][j] != mex[i][j - 1] && mex[i][j] != mex[i + 1][j])
				l[j].push_back(i);
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] |= dp[i - 1][j];
			for (auto &k : l[i])
			    if ((j ^ mex[k][i]) <= n)
					dp[i][j] |= dp[k - 1][j ^ mex[k][i]];
		}
	}
	for (int i = n; i >= 0; i--)
		if (dp[n][i] == 1)
			return i;
	assert(0);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) 
		printf("%d\n", sol());
	return 0;
}
