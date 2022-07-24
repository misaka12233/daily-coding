#include <bits/stdc++.h>
using namespace std;
const int maxn = 500 + 10;
const long long inf = 0xffffffffffffff;
template <typename type>
void read(type &a) 
{
    int t, f = 0;
    while (!isdigit(t = getchar())) 
        f |= t == '-';
    a = t - '0';
    while ( isdigit(t = getchar())) 
    {
        a *= 10;
        a += t - '0';
    }
    a = f ? -a : a;
}
int n;
long long sum[maxn], dp[maxn][maxn];
int decide[maxn][maxn];
void Print(int st, int len)
{
    if (len == 0) return;
    int p = decide[st][len];
    printf("%d ", st + p - 1);
    Print(st, p - 1);
    Print(st + p, len - p);
}
int main()
{
    read(n);
    for (int i = 1; i <= n; i++) 
    {
        read(dp[i][1]);
        decide[i][1] = 1;
        sum[i] = sum[i - 1] + dp[i][1];
    }
    for (int l = 2; l <= n; l++)
    {
        for (int i = 1; i + l - 1 <= n; i++)
        {
            dp[i][l] = inf;
            int p;
            for (int j = 1; j <= l; j++)
            {
                if (dp[i][l] > dp[i][j - 1] + dp[i + j][l - j] + sum[i + l - 1] - sum[i - 1])
                {
                    dp[i][l] = dp[i][j - 1] + dp[i + j][l - j] + sum[i + l - 1] - sum[i - 1];
                    p = j;
                }
            }
           decide[i][l] = p;
        }
    }
    printf("%lld\n", dp[1][n]);
    Print(1, n);
    return 0;
}