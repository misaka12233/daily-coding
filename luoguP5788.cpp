#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000000 + 10;
const int inf = 0x7fffffff;
int n;
int a[maxn], sta[maxn], top;
int f[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    a[0] = inf;
    sta[++top] = 0;
    for (int i = n; i >= 1; i--)
    {
        while (a[i] >= a[sta[top]])
            top--;
        f[i] = sta[top];
        sta[++top] = i;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", f[i]);
    return 0;
}