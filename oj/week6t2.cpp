#include <bits/stdc++.h>
using namespace std;
const int maxn = 10 + 10;
const int inf = 0x7fffffff;
int r, n, m, l;
long long A[maxn][maxn];
int p[maxn];
int B[maxn][maxn], C[maxn][maxn], D[maxn][maxn];
int main()
{
    scanf("%d", &r);
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= r; j++)
            scanf("%lld", &A[i][j]);
    bool flag = true;
    for (int i = 1; i <= r; i++)
        p[i] = i;
    long long ans = 0;
    while (flag == true)
    {
        int cnt = 0;
        long long s = 1;
        for (int i = 1; i < r; i++)
        {
            int t = p[i];
            for (int j = i + 1; j <= r; j++)
            {
                if (p[j] < t)
                    cnt++;
            }
        }
        if (cnt & 1)
            s = -1;
        for (int i = 1; i <= r; i++)
            s = s * A[i][p[i]];
        ans += s;
        flag = next_permutation(p + 1, p + r + 1);
    }
    printf("%lld\n", ans);
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &B[i][j]);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= l; j++)
            scanf("%d", &C[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= l; j++)
            for (int k = 1; k <= m; k++)
                D[i][j] += B[i][k] * C[k][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= l; j++)
            printf("%d ", D[i][j]);
        puts("");
    }
    return 0;
}