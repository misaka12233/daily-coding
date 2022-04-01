#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000000 + 10;
const int inf = 0x7fffffff;
int n;
int h[maxn], a[maxn], sta[maxn], top;
long long ans, cnt[maxn];
bool vis[maxn];
int main()
{
    scanf("%d", &n);
    int mx = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &h[i]);
        if (h[i] > h[mx])
            mx = i;
    }
    for (int i = 1; i <= n; i++)
        a[i] = h[(mx + i - 2) % n + 1];
    a[++n] = h[mx];
    a[0] = inf;
    top = 0;
    sta[++top] = 0;
    for (int i = n; i >= 1; i--)
    {
        while (a[i] >= a[sta[top]])
        {
            if (a[i] == a[sta[top]])
                cnt[i] = cnt[sta[top]] + 1, ans += cnt[i];
            top--;
        }
        if (top != 1)
            ans++;
        if (sta[top] == n)
            vis[i] = true;
        sta[++top] = i;
    }
    top = 0;
    sta[++top] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] >= a[sta[top]])
            top--;
        if (top != 1 && (sta[top] != 1 || !vis[i]))
            ans++;
        sta[++top] = i;
    }
    printf("%lld\n", ans - cnt[1]);
    return 0;
}