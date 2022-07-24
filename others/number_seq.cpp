#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int main()
{
    double sum = 0, p = 0.25;
    for (int i = 1; i <= maxn; i++, p *= 0.25)
        sum += p * (3 * i + 6);
    printf("%lf\n", sum);
    return 0;
}