#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
const int mod = 998244353;
int T;
int n;
long long a[maxn][maxn], b[maxn][maxn], c[maxn][maxn];
long long r[maxn], res[maxn], ans[maxn];
template<typename T> void fread(T &x)
{
    char ch = getchar();
    int f = 1;
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') f = -1;
        ch = getchar();
    }
    x = 0;
    while ('0' <= ch && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x = x * f;
}
int main()
{
    srand(time(0));
    fread(T);
    while (T--)
    {
        fread(n);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fread(a[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fread(b[i][j]);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                fread(c[i][j]);
        int cnt = 2;
        bool chk = true;
        while (cnt--)
        {
            for (int i = 1; i <= n; i++)
            {
                r[i] = rand() % 100;
                res[i] = ans[i] = 0;
            }
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    res[i] += r[j] * a[j][i];
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    ans[i] += res[j] * b[j][i];
            for (int i = 1; i <= n; i++)
            {
                long long sum = 0;
                for (int j = 1; j <= n; j++)
                    sum += r[j] * c[j][i];
                if (sum != ans[i])
                {
                    chk = false;
                    break;
                }
            }
            if (!chk) break;
        }
        if (chk) puts("YES");
        else puts("NO");
    }
    return 0;
}