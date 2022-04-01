#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
const int inf = 0x7fffffff;
int n, a[maxn];
int getmax(int rank)
{
    if (rank == n)
        return a[rank];
    return max(a[rank], getmax(rank + 1));
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("%d\n", getmax(1));
    return 0;
}