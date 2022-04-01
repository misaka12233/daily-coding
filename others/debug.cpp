#include <cstdio>
using namespace std;
char map[3002][3002];
long long memory[3002][3002];
long long n, m;
long long mod;
long long f(long long x, long long y);
int main()
{
    scanf("%lld %lld", &n, &m);
    getchar();
    mod = 1e9 + 9;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 1; j <= m; j++)
        {
            scanf("%c", &map[i][j]);
            memory[i][j] = -1;
        }
        getchar();
    }
    for (int i = 0; i <= n + 1; i++)
    {
        map[i][0] = 'X';
        map[i][m + 1] = 'X';
        memory[i][0] = -1;
        memory[i][m + 1] = -1;
    }
    for (int i = 0; i <= m + 1; i++)
    {
        map[0][i] = 'X';
        map[n + 1][i] = 'X';
        memory[0][i] = -1;
        memory[n + 1][i] = -1;
    }
    if (map[n][m] == 'X')
        printf("%d", 0);
    else
        printf("%lld", f(1, 1));
}
long long f(long long x, long long y)
{
    if (memory[x][y] != -1)
        return memory[x][y];
    else
    {
        if (map[x][y] == 'X')
        {
            memory[x][y] = 0;
            return memory[x][y];
        }
        else
        {
            if ((x == n - 1 && y == m) || (x == n && y == m - 1))
            {
                memory[x][y] = 1;
                return memory[x][y];
            }
            else
            {
                memory[x][y] = (f(x + 1, y) % mod + f(x, y + 1) % mod) % mod;
                return memory[x][y];
            }
        }
    }
}
