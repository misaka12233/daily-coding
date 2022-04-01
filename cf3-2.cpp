#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const long long inf = 0x7fffffff;
int t;
long long n, k, ans;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld", &n, &k);
        long long now = 1;
        ans = 0;
        while (now <= k && now < n)
            now <<= 1, ans++;
        ans += (n - now + k - 1) / k;
        printf("%lld\n", ans);
    }
    return 0;
}