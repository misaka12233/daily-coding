#include <bits/stdc++.h>
using namespace std;
long long f[100][2];
int main()
{
    int n;
    scanf("%d", &n);
    f[1][0] = f[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        f[i][0] = f[i - 1][1];
        f[i][1] = f[i - 1][0] + f[i - 1][1];
    }
    printf("%lld\n", f[n][0] + f[n][1]);
    return 0;
}
