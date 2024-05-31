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
				l[i - 1].push_back(j);
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (dp[i][j] == 1)
			{
				dp[i + 1][j] = 1;
				for (auto &k : l[i])
					dp[k][j ^ mex[i + 1][k]] = 1;
			}
		}
	}
	for (int i = n; i >= 0; i--)
		if (dp[n][i] == 1)
			return i;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) 
		printf("%d\n", sol());
	return 0;
}

