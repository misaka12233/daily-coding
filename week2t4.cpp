#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        long long x;
        scanf("%lld", &x);
        if (x <= 14 && x >= 4)
            puts("T");
        else
            puts("F");
    }
    return 0;
}