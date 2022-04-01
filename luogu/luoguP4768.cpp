#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
int T;
int n, m;

int hd[maxn], tot, dis[maxn];
bool vis[maxn];
struct node1
{
    int len;
    int h;
    int from, end;
    int nxt;
};
node1 edge[maxn * 4];
priority_queue< pair<int, int> > q;
void add(int u, int v, int w, int h)
{
    tot++;
    edge[tot].from = u;
    edge[tot].end = v;
    edge[tot].len = w;
    edge[tot].h = h;
    edge[tot].nxt = hd[u];
    hd[u] = tot;
}
void dij()
{
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[1] = 0;
    q.push(make_pair(-dis[1], 1));
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = hd[u]; i; i = edge[i].nxt)
        {
            int v = edge[i].end;
            if (dis[v] > dis[u] + edge[i].len)
            {
                dis[v] = dis[u] + edge[i].len;
                q.push(make_pair(-dis[v], v));
            }
        }
    }
}

int fa[maxn * 2], k;
struct node2
{
    int h;
    int mind;
};
node2 tr[maxn * 2];
int f[maxn * 2][20];
bool cmp(node1 x, node1 y)
{
    return x.h > y.h;
}
int getfa(int x)
{
    if (x == fa[x])
        return x;
    return fa[x] = getfa(fa[x]);
}
void kruskal()
{
    k = 0;
    memset(f, 0, sizeof(f));
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        k++;
        tr[k].h = 0x7fffffff;
        tr[k].mind = dis[i];
    }
    sort(edge + 1, edge + tot + 1, cmp);
    for (int i = 1; i <= tot; i++)
    {
        int u = edge[i].from, v = edge[i].end;
        int fx = getfa(u), fy = getfa(v);
        if (fx == fy)
            continue;
        k++;
        tr[k].h = edge[i].h;
        tr[k].mind = min(tr[fx].mind, tr[fy].mind);
        f[fx][0] = f[fy][0] = fa[fx] = fa[fy] = k;
        fa[k] = k;
    }
    for (int l = 1; l <= 19; l++)
        for (int i = 1; i <= k; i++)
            f[i][l] = f[f[i][l - 1]][l - 1];
}

int Q, op, s;
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        tot = 0;
        memset(hd, 0, sizeof(hd));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v, w, h;
            scanf("%d%d%d%d", &u, &v, &w, &h);
            add(u, v, w, h);
            add(v, u, w, h);
        }
        dij();
        kruskal();
        int ans = 0;
        scanf("%d%d%d", &Q, &op, &s);
        for (int i = 1; i <= Q; i++)
        {
            int v, p;
            scanf("%d%d", &v, &p);
            v = (v + op * ans - 1) % n + 1;
            p = (p + op * ans) % (s + 1);
            for (int i = 19; i >= 0; i--)
                if (tr[f[v][i]].h > p)
                    v = f[v][i];
            ans = tr[v].mind;
            printf("%d\n", ans);
        }
    }
    return 0;
}
