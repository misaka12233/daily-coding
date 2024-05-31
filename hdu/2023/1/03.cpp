#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;
const int maxm = 20 + 5;
int T;
ll v[maxm];
ll Pk[maxm];
int a[maxn];
int n, m, R, P;
ll f[maxn][maxn][maxm][maxm];
void sol()
{
    scanf("%d%d%d%d", &n, &m, &R, &P);
    R = min(R, (int)(log(n) / log(2)) + 1);
    Pk[1] = 1, Pk[2] = P;
    for (int i = 3; i <= R; i++)
        Pk[i] = Pk[i - 1] * P;
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= m; i++)
        scanf("%lld", v + i);
    for (int l = 1; l <= n; l++)
        for (int r = l; r <= n; r++)
            for (int x = 0; x <= m; x++)
                for (int k = 0; k <= R; k++)
                    f[l][r][x][k] = -1e15;
    for (int len = 0; len < n; len++)
    {
        for (int l = 1; l + len <= n; l++)
        {
            int r = l + len;
            
            for (int i = l; i <= r; i++)
                f[l][r][a[i]][1] = max(f[l][r][a[i]][1], f[l][i - 1][0][0] + f[i + 1][r][0][0]);
                
            for (int x = 1; x <= m; x++)
            {
                f[l][r][0][0] = max(f[l][r][0][0], f[l][r][x][1] + v[x]);
                for (int k = 2; k <= R; k++)
                {
                    for (int i = l; i < r; i++)
                        f[l][r][x][k] = max(f[l][r][x][k], f[l][i][x][k - 1] + f[i + 1][r][x][k - 1]);
                    f[l][r][0][0] = max(f[l][r][0][0], f[l][r][x][k] + v[x] * Pk[k]);
                }
            }
                    
            for (int i = 1; i < r; i++)
                f[l][r][0][0] = max(f[l][r][0][0], f[l][i][0][0] + f[i + 1][r][0][0]);
        }
    }
    printf("%lld\n", f[1][n][0][0]);
}
int main()
{
    scanf("%d", &T);
    while (T--) sol();
    return 0;
}
