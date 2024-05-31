#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
int a[100];
int partition(int l, int r, int x)
{
    int i = l, j = r, tmp;
    while (i < j)
    {
        while (i < j && a[i] < x) 
            i = i + 1;
        while (i < j && a[j] > x) 
            j = j - 1;
        if (i < j)
        {
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i = i + 1;
            j = j - 1;
        }
    }
    return j;
}
int qsort(int l, int r)
{
    int mid;
    if (l >= r)
        return 0;
    mid = partition(l, r, a[l]);
    qsort(l, mid);
    qsort(mid + 1, r);
    return 0;
}
int main()
{
    int i = 0;
    scanf("%d", &n);
    while (i < n)
    {
        scanf("%d", a + i);
        i = i + 1;
    }
    qsort(0, n - 1);
    i = 0;
    while (i < n)
    {
        printf("%d\n", a[i]);
        i = i + 1;
    }
    return 0;
}

