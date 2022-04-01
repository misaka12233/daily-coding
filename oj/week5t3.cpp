#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000000 + 10;
int N;
long long f[maxn];
long long fun(int x)
{
    if (x == 0)
        return 0;
    if (x <= 10000000)
    {
        if (f[x] == 0)
            f[x] = 3 * fun(max((int)floor(pow(x, 0.8)) - 1, 0)) + 2 * fun(x / 2) + x;
        return f[x];
    }
    return 3 * fun(max((int)floor(pow(x, 0.8)) - 1, 0)) + 2 * fun(x / 2) + x;
}
int main()
{
    long long x;
    scanf("%d", &N);
    f[1] = 1;
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", &x);
        printf("%lld ", fun(x));
    }
    return 0;
}