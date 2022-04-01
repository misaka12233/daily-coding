#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 10;
int n, m;
int a[maxn];
struct node
{
    int lc, rc;
    int sum;
};
node tr[maxn * 24];
int rt[maxn], tot;
int build(int l, int r)
{
    tot++;
    int x = tot;
    if (l == r)
    {
        tr[x].sum = a[l];
        return x;
    }
    int mid = l + r >> 1;
    tr[x].lc = build(l, mid);
    tr[x].rc = build(mid + 1, r);
    return x;
}
int update(int x, int l, int r, int p, int t)
{
    tot++;
    int y = tot;
    if (l == r)
    {
        tr[y].sum = t;
        return y;
    }
    int mid = l + r >> 1;
    if (p <= mid)
    {
        tr[y].lc = update(tr[x].lc, l, mid, p, t);
        tr[y].rc = tr[x].rc;
    }
    else
    {
        tr[y].lc = tr[x].lc;
        tr[y].rc = update(tr[x].rc, mid + 1, r, p, t);
    }
    return y;
}
int query(int x, int l, int r, int p)
{
    if (l == r)
        return tr[x].sum;
    int mid = l + r >> 1;
    if (p <= mid)
        return query(tr[x].lc, l, mid, p);
    else
        return query(tr[x].rc, mid + 1, r, p);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    rt[0] = build(1, n);
    for (int i = 1; i <= m; i++)
    {
        int v, op, loc, val;
        scanf("%d%d", &v, &op);
        if (op == 1)
        {
            scanf("%d%d", &loc, &val);
            rt[i] = update(rt[v], 1, n, loc, val);
        }
        else
        {
            scanf("%d", &loc);
            rt[i] = rt[v];
            printf("%d\n", query(rt[v], 1, n, loc));
        }
    }
    return 0;
}
