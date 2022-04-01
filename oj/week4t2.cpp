#include <bits/stdc++.h>
using namespace std;
long long f(long long x)
{
    if (x == 0)
        return 0;
    return 2 * f(sqrt(x) / 3) + 3 * f(sqrt(x) / 2) + x / 2;
}
int main()
{
    long long x;
    scanf("%lld", &x);
    printf("%lld\n", f(x));
    return 0;
}