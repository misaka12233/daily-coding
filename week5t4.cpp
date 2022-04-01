#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n;
int a[maxn], f[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    f[n + 1] = -maxn;
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0)
            f[i] = 0;
        else
            f[i] = f[i + 1] + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (f[i] < 0)
            puts("overflow");
        else
            printf("%d\n", f[i]);
    }
    return 0;
}