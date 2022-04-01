#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 10;
const int mod = 998244353;
int n, m;
int dp[maxn][maxn], sum[maxn][maxn];
int main()
{
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        sum[0][i] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            dp[i][j] = sum[i - 1][j];
            sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
        }
    }
    printf("%d\n", sum[n][m]);
	return 0;
}

