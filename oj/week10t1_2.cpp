#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int n, m, k;
int a[maxn];
int ans = 1;
bool check(int x)
{
    if (x <= ans || x > k) return false;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] % x == 0)
            cnt++;
    return cnt >= m;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) 
        scanf("%d", a + i);
    for (int i = 1; i <= 16; i++)
    {
        int x = a[rand() % n + 1];
        int t = sqrt(x);
        for (int j = 1; j <= t; j++)
        {
            if (x % j == 0)
            {
                if (check(j)) ans = j;
                if (check(x / j)) ans = x / j;
            }
        }
    }
    if (m == 0) printf("%d\n", k);
    else printf("%d\n", ans);
    return 0;
}