#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 7ll << 50 | 1;
const int maxn = 1000000 + 10;
int n, m, k;
ll ans[2][maxn];
ll inv[2];
int dirx[4] = {1, -1, 0, 0}, diry[4] = {0, 0, 1, -1};
ll getinv(__int128 x)
{
    ll p = mod - 2;
    __int128 res = 1;
    while (p)
    {
        if (p & 1) res = res * x % mod;
        p >>= 1;
        x = x * x % mod;
    }
    return res;
}
void addeq(ll &x, ll y)
{
    x = x + y;
    if (x > mod) x -= mod;
}
int calc(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m) return 0;
    return (x - 1) * m + y;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    char c;
    for (int i = 1; i <= n; i++)
    {
        c = getchar();
        for (int j = 1; j <= m; j++)
        {
            c = getchar();
            if (c == '1')
                ans[0][calc(i, j)] = 1;
        }
    }
    inv[0] = getinv(4);
    inv[1] = getinv(n * m);
    int now = 1, pre = 0;
    for (int t = 1; t <= k; t++, now ^= 1, pre ^= 1)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ans[now][calc(i, j)] = 0;
                if (ans[pre][calc(i, j)] == 0) continue;
                for (int l = 0; l < 4; l++)
                    addeq(ans[now][calc(i, j)], ans[pre][calc(i + dirx[l], j + diry[l])]);
            }
        }
    }
    __int128 tmp = 1;
    for (int i = 1; i <= k; i++) tmp = tmp * inv[0] % mod;
    ll res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            addeq(res, ans[pre][calc(i, j)]);
    tmp = tmp * res % mod;
    tmp = tmp * inv[1] % mod;
    res = tmp;
    printf("%lld\n", res);
    return 0;
}