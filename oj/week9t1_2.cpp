#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int inf = 0x3f3f3f3f;
int T;
double p[maxn], f[maxn];
int n, m, k;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &k, &m);
        p[n] = 1.0;
        for (int i = 0; i < n; i++)
            scanf("%lf", p + i), p[n] -= p[i];
        for (int i = 1; i <= m; i++)
        {
            double res = 1.0;
            f[i] = 0;
            for (int j = 0; j <= n; j++)
            {
                f[i] += res * p[j]; // f[i] = sum(f[i-1]^j * p[j])
                res *= f[i - 1];
            }
        }
        double ans = 1.0;
        for (int j = 1; j <= k; j++) ans *= f[m];
        printf("%.12lf\n", ans);
    }
    return 0;
}