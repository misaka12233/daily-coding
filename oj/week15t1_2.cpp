#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000 + 10;
int T;
char suki[maxn][maxn];
long long ans, n;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%lld", &n);
        ans = n * (n - 1) * (n - 2) / 6;
        for (int i = 1; i <= n; i++)
            scanf("%s", suki[i] + 1);
        for (int j = 1; j <= n; j++)
        {
            long long cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (i == j) continue;
                if (suki[i][j] == 'Y') cnt++;
            }
            ans -= cnt * (cnt - 1) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}