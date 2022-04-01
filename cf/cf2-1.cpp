#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        int a, b, c, sum;
        scanf("%d%d%d", &a, &b, &c);
        sum = a + 2 * b + 3 * c;
        sum %= 6;
        sum %= 4;
        if (2 * a < sum) 
            printf("%d\n", sum - 2 * a);
        else
            printf("%d\n", sum & 1);
    }
    return 0;
}