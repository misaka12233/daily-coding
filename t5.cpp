#include <bits/stdc++.h>
using namespace std;
int n, m, now;
int d[30010];
char c[30010][3];
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &d[i]);
        scanf("%s", c[i]);
    }
    now = 1;
    for(int i = 1; i <= m; i++)
    {
        int op, p;
        scanf("%d%d", &op, &p);
        p %= n;
        op = op ^ d[now];
        if(op) 
        {
            now += p;
            if(now > n) now -= n;
            printf("%s\n", c[now]);
        }
        else
        {
            now -= p;
            if(now <= 0) now += n;
            printf("%s\n", c[now]);
        }
    }
    return 0;
}
