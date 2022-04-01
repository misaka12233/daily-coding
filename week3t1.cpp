#include <bits/stdc++.h>
using namespace std;
int a[2][25][25], n, m, k;
int main()
{
    int now;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &a[0][i][j]);
    now = 0;
    while (k--)
    {
        int op;
        scanf("%d", &op);
        if (op == 3)
        {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= m; j++)
                    a[now ^ 1][j][n - i + 1] = a[now][i][j];
            now ^= 1;
            swap(n, m);
        }
        else
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (op == 1)
            {
                if (1 <= x && x <= n && 1 <= y && y <= n)
                {
                    for (int i = 1; i <= m; i++)
                        swap(a[now][x][i], a[now][y][i]);
                }
                else
                {
                    puts("Invalid arguments!");
                    continue;
                }
            }
            else
            {
                if (1 <= x && x <= m && 1 <= y && y <= m)
                {
                    for (int i = 1; i <= n; i++)
                        swap(a[now][i][x], a[now][i][y]);
                }
                else
                {
                    puts("Invalid arguments!");
                    continue;
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                printf("%d ", a[now][i][j]);
            puts("");
        }
    }
    return 0;
}