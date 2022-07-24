#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
char s[2][maxn][15];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    scanf("%s%s", s[0][i], s[1][i]);
    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        bool chk[2] = {true, true};
        for (int a = 0; a <= 1; a++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                for (int b = 0; b <= 1; b++)
                {
                    if (strcmp(s[a][i], s[b][j]) == 0)
                    {
                        chk[a] = false;
                        break;
                    }
                }
                if (!chk[a]) break;
            }
        }
        if (!chk[0] && !chk[1])
        {
            ans = false;
            break;
        }
    }
    if (ans) puts("Yes");
    else puts("No");
    return 0;
}