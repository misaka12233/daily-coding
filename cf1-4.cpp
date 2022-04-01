#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[50];
const int inf = 0x3f3f3f3f;
int gcd(int x, int y)
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int mx = -inf, mn = inf;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]), mx = max(a[i], mx), mn = min(a[i], mn);
        int ans = mx - mn;
        if (ans == 0)
        {
            puts("-1");
            continue;
        }
        for (int i = 1; i <= n; i++)
            for (int j = i + 1; j <= n; j++)
                ans = gcd(ans, abs(a[i] - a[j]));
        printf("%d\n", ans);
    }
    return 0;
}