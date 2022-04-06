#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int maxm = 3000000 + 10;
const int inf = 0x3f3f3f3f;
double p[maxn];
int n, m, k;
struct node{
    int ed;
    int nxt;
}edge[maxm];
int head[maxn], tot;
int indeg[maxn], outdeg[maxn];
queue<int> q;
void add(int x, int y)
{
    tot++;
    edge[tot].ed = y;
    edge[tot].nxt = head[x];
    head[x] = tot;
    indeg[y]++;
    outdeg[x]++;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    p[0] = 1.0;
    for (int i = 0; i <= n; i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = edge[i].nxt)
        {
            int y = edge[i].ed;
            p[y] += p[x] / outdeg[x];
            indeg[y]--;
            if (indeg[y] == 0)
                q.push(y);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int idx;
        scanf("%d", &idx);
        printf("%.12lf\n", p[idx]);
    }
    return 0;
}