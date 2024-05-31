#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define maxn 20000 + 10
int n, m;

struct node{
    int u, v;
    int w;
    int valid;
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

int size[maxn];

int main()
{
    srand(time(0));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        size[e[i].u]++;
        e[i].valid = 1;
    }
    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        for (int i = 1; i <= m; i++)
            if (e[i].u == u && e[i].v == v)
                e[i].valid = 0, size[e[i].u]--;
    }
    quick_sort(1, m);
    int st = 1;
    while (size[e[st].u] == 0)
        st++;
    printf("%d:", e[st].u);
    for (int i = st; i < m; i++)
    {
        if (e[i].valid)
            printf("(%d,%d,%d)", e[i].u, e[i].v, e[i].w);
        if (e[i].u != e[i + 1].u)
            if (size[e[i + 1].u])
                printf("\n%d:", e[i + 1].u);
    }
    if (e[m].valid)
        printf("(%d,%d,%d)", e[m].u, e[m].v, e[m].w);
    return 0;
}
