#include <bits/stdc++.h>
using namespace std;
int T;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        n++;
        if (n == 1)
            puts("0");
        else
        {
            if (n % 2 == 0)
                n >>= 1;
            printf("%d\n", n);
        }
    }
    return 0;
}
