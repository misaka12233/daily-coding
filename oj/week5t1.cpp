#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
int n, ans;
int a[maxn], b[maxn];
int tr[1000010];
int lowbit(int x)
{
    return x & -x;
}
void add(int x)
{
    for (int i = x; i <= 1000000; i += lowbit(i))
        tr[i]++;
    return;
}
int query(int x)
{
    int sum = 0;
    for (int i = x - 1; i; i -= lowbit(i))
        sum += tr[i];
    return sum;
}
int halfSearch(int x)
{
    int l = 1, r = n, mid;
    while (l < r)
    {
        mid = l + r >> 1;
        if(b[mid] >= x) 
            r = mid;
        else 
            l = mid + 1;
    }
    return l;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), b[i] = a[i];
    sort(b + 1, b + n + 1);
    for (int i = n; i >= 1; i--)
    {
        int x = halfSearch(a[i]);
        add(x);
        ans += query(x);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", b[i]);
    printf("\n%d\n", ans);
    return 0;
}