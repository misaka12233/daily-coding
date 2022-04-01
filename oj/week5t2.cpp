#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000 + 10;
int x, ans;
long long f[maxn];
long long fun(int x)
{
    f[x] = 1;
    for (int i = 1; i <= x / 3; i++)
    {
        if (f[i] == 0)
            f[i] = fun(i);
        f[x] += f[i];
    }
    return f[x];
}
int main()
{
    scanf("%d", &x);
    printf("%lld\n", fun(x));
    return 0;
}