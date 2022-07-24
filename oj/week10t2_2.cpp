#include <bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
const int mod = 998244353;
int n;
int a[maxn];
int inv(int x)
{
    int res = 1, k = mod - 2;
    while (k)
    {
        if (k & 1) res = 1ll * res * x % mod;
        k >>= 1;
        x = 1ll * x * x % mod;
    }
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int p = inv(n);
    for (int i = 1; i <= n; i++)
    {
        int t = a[i], s = 0;
        for (int j = 1; j <= n; j++)
        {
            s = (s + a[j]) % mod;
            a[j] = (1ll * (n - 1) * a[j] + t) % mod;
            a[j] = 1ll * p * a[j] % mod;
        }
        a[i] = 1ll * p * s % mod;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}