#include <bits/stdc++.h>
using namespace std;
long long f[110000];
int main()
{
    f[1] = 1;
    for (int i = 2; i <= 100000; i++)
        f[i] = f[i - 1] + f[i / 2] + i;
    printf("%lld\n", f[100000]);
    return 0;
}