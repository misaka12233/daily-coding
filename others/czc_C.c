#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define maxn 20000 + 10
int n, m;

struct node{
    int u, v;
};
struct node e[maxn];
int compare(struct node x, struct node y)
{
    if (x.u == y.u)  return x.v < y.v;
    return x.u < y.u;
}
void quick_sort(int l, int r)
{
    int i = l, j = r, t;
    struct node mid;
    t = rand() % (r - l + 1) + l;
    mid = e[t];
    while (i <= j)
    {
        while (compare(mid, e[j]))
            j--;
        while (compare(e[i], mid))
            i++;
        if (i <= j)
        {
            struct node tmp;
            tmp = e[i];
            e[i] = e[j];
            e[j] = tmp;
            i++, j--;
        }
    }
    if (i < r)
        quick_sort(i, r);
    if (l < j)
        quick_sort(l, j);
}

int start[maxn], end[maxn];
int vis[maxn];

void dfs(int u)
{
    vis[u] = 1;
    printf("%d ", u);
    if (start[u] == 0) return;
    for (int i = start[u]; i <= end[u]; i++)
    {
        int v = e[i].v;
        if (vis[v]) continue;
        dfs(v);
    }
}

int main()
{
    srand(time(0));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &e[i].u, &e[i].v);
    quick_sort(1, m);
    start[e[1].u] = 1;
    for (int i = 1; i < m; i++)
    {
        if (e[i].u != e[i + 1].u)
        {
            end[e[i].u] = i;
            start[e[i + 1].u] = i + 1;
        }
    }
    end[e[m].u] = m;
    for (int i = 0; i < n; i++)
        if (!vis[i])
            dfs(i);
    return 0;
}
