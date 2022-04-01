#include <bits/stdc++.h>
using namespace std;
const int maxn = 60 + 10;
int T;
int n;
long long cnt1, cnt0, pow2[maxn];
int a[maxn];
int main()
{
    scanf("%d", &T);
    pow2[0] = 1;
    for(int i = 1 ;i <= 60; i++)
        pow2[i] = 2 * pow2[i - 1];
    while (T--)
    {
        scanf("%d", &n);
        cnt1 = cnt0 = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] == 1) 
                cnt1++;
            if (a[i] == 0)
                cnt0++;
        }
        printf("%lld\n", cnt1 * pow2[cnt0]);
    }
    return 0;
}