#include <bits/stdc++.h>
using namespace std;
const int maxn = 300000 + 10;
const int inf = 0x7fffffff;
int n, m, tot;
struct node
{
    int lc;
    int rc;
    int lst;
};
node tr[maxn << 6];
int rt[maxn << 1];
int pow2[30];
int add(int x, int val, int rank, int dep)
{
    int now = ++tot;
    if (dep < 24)
    {
        if (val / pow2[23 - dep])
        {
            tr[now].lc = tr[x].lc;
            tr[now].rc = add(tr[x].rc, val % pow2[23 - dep], rank, dep + 1);
        }
        else
        {
            tr[now].lc = add(tr[x].lc, val % pow2[23 - dep], rank, dep + 1);
            tr[now].rc = tr[x].rc;
        }
    }
    tr[now].lst = max(tr[x].lst, rank);
    return now;
}
int query(int now, int val, int rank, int dep)
{
    if (dep == 24)
        return 0;
    int p = val / pow2[23 - dep];
    if (p == 0)
    {
        if (tr[tr[now].rc].lst < rank)
            return query(tr[now].lc, val % pow2[23 - dep], rank, dep + 1);
        else
            return pow2[23 - dep] + query(tr[now].rc, val % pow2[23 - dep], rank, dep + 1);
    }
    else
    {
        if (tr[tr[now].lc].lst < rank)
            return query(tr[now].rc, val % pow2[23 - dep], rank, dep + 1);
        else
            return pow2[23 - dep] + query(tr[now].lc, val % pow2[23 - dep], rank, dep + 1);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    int s = 0, x;
    pow2[0] = 1;
    for (int i = 1; i <= 24; i++)
        pow2[i] = pow2[i - 1] * 2;
    rt[0] = add(0, s, 1, 0);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        s = s ^ x;
        rt[i] = add(rt[i - 1], s, i + 1, 0);
    }
    char c[4];
    for (int i = 1; i <= m; i++)
    {
        scanf("%s", c);
        if (c[0] == 'A')
        {
            scanf("%d", &x);
            s = s ^ x;
            rt[n + 1] = add(rt[n], s, n + 2, 0);
            n++;
        }
        else
        {
            int l, r;
            scanf("%d%d%d", &l, &r, &x);
            x = s ^ x;
            printf("%d\n", query(rt[r - 1], x, l, 0));
        }
    }
    return 0;
}