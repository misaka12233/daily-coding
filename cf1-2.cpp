#include <bits/stdc++.h>
using namespace std;
int t;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        long long n, ans1 = 0, ans2 = 0;
        scanf("%lld", &n);
        long long tmp = n;
        while (tmp % 10 != 5)
        {
            ans1++;
            tmp /= 10;
            if (tmp == 0)
                break;
        }
        tmp /= 10;
        while (tmp % 10 != 2 && tmp % 10 != 7)
        {
            ans1++;
            tmp /= 10;
            if (tmp == 0)
                break;
        }
        tmp = n;
        while (tmp % 10 != 0)
        {
            ans2++;
            tmp /= 10;
            if (tmp == 0)
                break;
        }
        tmp /= 10;
        while (tmp % 10 != 5 && tmp % 10 != 0)
        {
            ans2++;
            tmp /= 10;
            if (tmp == 0)
                break;
        }
        printf("%lld\n", min(ans1, ans2));
    }
    return 0;
}