#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, m, tot;
struct node
{
    int lc;
    int rc;
    int fa;
    int dep;
};
node tr[maxn << 5];
int rt[maxn << 1];
int build(int l, int r)
{
    int x = ++tot;
    if (l == r)
    {
        tr[x].fa = l;
        return x;
    }
    int mid = l + r >> 1;
    tr[x].lc = build(l, mid);
    tr[x].rc = build(mid + 1, r);
    return x;
}
int update(int now, int l, int r, int pos, int val)
{
    int x = ++tot;
    if (l == r)
    {
        tr[x].fa = val;
        tr[x].dep++;
        return x;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
    {
        tr[x].lc = update(tr[now].lc, l, mid, pos, val);
        tr[x].rc = tr[now].rc;
    }
    else
    {
        tr[x].lc = tr[now].lc;
        tr[x].rc = update(tr[now].rc, mid + 1, r, pos, val);
    }
    return x;
}
node getnode(int now, int l, int r, int pos)
{
    if (l == r)
        return tr[now];
    int mid = l + r >> 1;
    if (pos <= mid)
        return getnode(tr[now].lc, l, mid, pos);
    else
        return getnode(tr[now].rc, mid + 1, r, pos);
}
int getfa(int x, int version)
{
    node tmp = getnode(rt[version], 1, n, x);
    if (tmp.fa == x)
        return x;
    return getfa(tmp.fa, version);
}
void adddep(int now, int l, int r, int pos)
{
    if (l == r)
    {
        tr[now].dep++;
        return;
    }
    int mid = l + r >> 1;
    if (pos <= mid)
        adddep(tr[now].lc, l, mid, pos);
    else
        adddep(tr[now].rc, mid + 1, r, pos);
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    rt[0] = build(1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, k, x, y;
        scanf("%d", &op);
        if (op == 2)
        {
            scanf("%d", &k);
            rt[i] = rt[k];
        }
        else
        {
            scanf("%d%d", &x, &y);
            int fx = getfa(x, i - 1), fy = getfa(y, i - 1);
            if (op == 1)
            {
                rt[i] = rt[i - 1];
                if (fx == fy)
                    continue;
                int depx = getnode(rt[i - 1], 1, n, fx).dep, depy = getnode(rt[i - 1], 1, n, fy).dep;
                if (depx > depy)
                    swap(fx, fy);
                rt[i] = update(rt[i - 1], 1, n, fx, fy);
                if (depx == depy)
                    adddep(rt[i], 1, n, fy);
            }
            else
            {
                if (fx == fy)
                    puts("1");
                else
                    puts("0");
                rt[i] = rt[i - 1];
            }
        }
    }
    return 0;
}