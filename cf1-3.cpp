#include <bits/stdc++.h>
using namespace std;
int t, k;
long long x[400010], n;
bool check(int sum)
{
    long long pos = 0;
    for(int i = k - sum + 1; i <= k; i++)
    {
        if (pos >= x[i])
            return false;
        pos += n - x[i];
    }
    return true;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        int l, r, mid;
        scanf("%lld%d", &n, &k);
        for (int i = 1; i <= k; i++)
            scanf("%lld", &x[i]);
        sort(x + 1, x + k + 1);
        l = 0;
        r = k;
        while (l < r)
        {
            mid = l + r >> 1;
            if (check(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        printf("%d\n", l);
    }
    return 0;
}