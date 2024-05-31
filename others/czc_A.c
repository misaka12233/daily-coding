#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define maxn 20000 + 10
int n, m;

struct node{
    int u, v;
    int w;
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

int main()
{
    srand(time(0));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
    quick_sort(1, m);
    printf("%d:", e[1].u);
    for (int i = 1; i < m; i++)
    {
        printf("(%d,%d,%d)", e[i].u, e[i].v, e[i].w);
        if (e[i].u != e[i + 1].u)
            printf("\n%d:", e[i + 1].u);
    }
    printf("(%d,%d,%d)", e[m].u, e[m].v, e[m].w);
    return 0;
}
