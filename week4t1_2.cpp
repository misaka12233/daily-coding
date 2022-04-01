#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 10;
const int mod = 1000000009;
int n, m;
char s[maxn][maxn];
int dp[maxn][maxn];
int main()
{
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    scanf("%s", s[i] + 1);
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1][j] != 'X')
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            if (s[i][j - 1] != 'X')
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
        }
    }
    printf("%d\n", dp[n][m]);
	return 0;
}

