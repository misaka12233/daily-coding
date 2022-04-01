#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 64 + 5;
int m;
ll ans[maxn];
int main()
{
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        ll a, b, ancestor = -1;
        int depa = 0, depb = 0, k = 1;
        scanf("%lld%lld", &a, &b);
        while (a)
        {
            ans[++depa] = a;
            a >>= 1;
        }
        while (b)
        {
            if (ancestor == -1)
            {
                while (ans[k] > b) 
                   k++;
                if (ans[k] == b)
                    ancestor = b;
            }
            ++depb;
            b >>= 1;
        }
        printf("Case #%d: %d\n", i, depa + depb - 2 * (depa - k + 1));
    }
    return 0;
}