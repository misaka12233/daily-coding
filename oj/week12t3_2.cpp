#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int n, ans;
int h[maxn];
int sta[maxn], top;
int l[maxn], r[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", h + i);
    top = 0;
    sta[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        while (top > 0 && h[i] <= h[sta[top]]) top--;
        l[i] = sta[top];
        sta[++top] = i;
    }
    top = 0;
    sta[0] = n + 1;
    for (int i = n; i >= 1; i--)
    {
        while (top > 0 && h[i] <= h[sta[top]]) top--;
        r[i] = sta[top];
        sta[++top] = i;
    }
    for (int i = 1; i <= n; i++)
        ans = max(ans, h[i] * (r[i] - l[i] - 1));
    printf("%d\n", ans);
}