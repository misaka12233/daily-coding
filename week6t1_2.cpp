#include <bits/stdc++.h>
using namespace std;
const int maxn = 2000000 + 10;
int a[maxn];
int n;
int ans[maxn];
int Operate(int l, int r, int k, int id)
{
    if (l == r)
    {
        if (a[l] == k) return 0;
        else return 1;
    }
    int mid = l + r >> 1, cnt, res;
    cnt = 0;
    for (int i = l; i <= mid; i++)
        if (a[i] != k) 
            cnt++;
    res = cnt + Operate(mid + 1, r, k + 1, id << 1 | 1);
    cnt = 0;
    for (int i = mid + 1; i <= r; i++)
        if (a[i] != k) 
            cnt++;
    int tmp = Operate(l, mid, k + 1, id << 1);
    if (res <= cnt + tmp) ans[id] = 0;
    else
    {
        ans[id] = 1;
        res = cnt + tmp;
    }
    return res;
}
void Print(int l, int r, int k, int id)
{
    if (l == r)
    {
        printf("%d ", k);
        return;
    }
    int mid = l + r >> 1;
    if (ans[id] == 0)
    {
        for (int i = l; i <= mid; i++)
            printf("%d ", k);
        Print(mid + 1, r, k + 1, id << 1 | 1);
    }
    else
    {
        Print(l, mid, k + 1, id << 1);
        for (int i = mid + 1; i <= r; i++)
            printf("%d ", k);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    printf("%d\n", Operate(1, n, 1, 1));
    Print(1, n, 1, 1);
    return 0;
}
