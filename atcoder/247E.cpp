#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 200000 + 10;
int a[maxn];
int lstX[maxn], lstY[maxn], lstOut[maxn];
int n, x, y;
ll ans;
int main()
{
    scanf("%d", &n);
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    int nowX, nowY, nowOut;
    nowX = nowY = nowOut = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == x) nowX = i;
        if (a[i] == y) nowY = i;
        if (a[i] > x || a[i] < y) nowOut = i;
        lstX[i] = nowX;
        lstY[i] = nowY;
        lstOut[i] = nowOut;
    }
    for (int i = 1; i <= n; i++)
    {
        if (lstX[i] != 0 && lstY[i] != 0)
        {
            int lst = min(lstX[i], lstY[i]);
            if (lstOut[i] < lst) ans = ans + lst - lstOut[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}