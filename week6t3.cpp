#include <bits/stdc++.h>
using namespace std;
const int maxn = 25 + 10;
const long long inf = 0x7fffffffffffffff;
int k, n;
long long v[maxn];
long long dp[maxn][maxn];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &v[i]);
    for (int i = 1; i <= n; i++)
    {
        dp[i - 1][i] = -inf;
        for (int j = 1; j <= i; j++)
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] * 3 + v[i]);
    }
    printf("%lld\n", dp[n][k]);
    return 0;
}