#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 500000 + 5;

int n;
long long ans;
pii a[maxn];
pii b[maxn];
void mergeSort(int l, int r)
{
    if (l == r) return;
    int mid = l + r >> 1;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    int i = l, j = mid + 1, cnt = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            b[cnt] = a[i];
            cnt++;
            i++;
        }
        else
        {
            b[cnt] = a[j];
            ans = ans + mid - i + 1;
            cnt++;
            j++;
        }
    }
    while (i <= mid)
    {
        b[cnt] = a[i];
        cnt++;
        i++;
    }
    while (j <= r)
    {
        b[cnt] = a[j];
        cnt++;
        j++;
    }
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}
int main()
{
    scanf("%d", &n);
    int x, y;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        a[i] = pii(x, y);
    }
    long long res = 0;
    pii mn = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (mn > a[i]) res--;
        mn = min(mn, a[i]);
    }
    mergeSort(1, n);
    printf("%lld\n", 2 * ans + n - 1 + res);
    return 0;
}