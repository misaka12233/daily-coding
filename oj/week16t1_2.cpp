#include <bits/stdc++.h>
using namespace std;
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
const int maxn = 1000000 + 10;
const long long mod = 2000000007;

int T;
int k;
long long dp[maxn][2];
int main()
{
    read(T);
    read(k);
    dp[1][0] = dp[1][1] = 1;
    for (int i = 2; i <= 1000000; i++)
    {
        for (int l = 0; l <= 1; l++)
        {
            dp[i][l] = dp[i - 1][l];
            for (int j = max(1, i - k); j < i; j++)
                dp[i][l] = (dp[j][l ^ 1] + dp[i][l]) % mod;
        }
    }
    while (T--)
    {
        int x;
        read(x);
        printf("%lld\n", (dp[x][0] + dp[x][1]) % mod);
    }
    return 0;
}