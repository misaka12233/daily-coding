#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const long long inf = 0x7fffffff;
const long long mod = 998244353;
int n, x;
long long dp[maxn][maxn];
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 2; i <= n; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            for(int k = 0; k <= i - 2; k++)
            {
                dp[i][j] = (dp[i][j] + dp[k][j-i+k]*(i - k)^(i - k));
            }
        }
    }
}