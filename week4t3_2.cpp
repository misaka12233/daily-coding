#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10000000 + 10;
const int mod = 998244353;
int n, m, k, c;
int fac[maxn];
int ans;
int inv(int x)
{
    int p = mod - 2, res = 1;
    while (p)
    {
        if (p & 1) res = 1ll * res * x % mod;
        p >>= 1;
        x = 1ll * x * x % mod;
    }
    return res;
}
int C(int p, int q)
{
    int res = inv(fac[p]);
    for (int i = q - p + 1; i <= q; i++)
        res = 1ll * res * i % mod;
    return res;
}
int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &c);
    fac[0] = 1;
    for (int i = 1; i <= n + 1; i++)
        fac[i] = 1ll * fac[i - 1] * i % mod;
    ans = (1ll * c * C(n, m + n - 1) % mod + 1ll * k * C(n + 1, m + n) % mod) % mod;
    printf("%d\n", ans);
	return 0;
}

