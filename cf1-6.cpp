#include <bits/stdc++.h>
using namespace std;
int t;
int n, k;
int deg[400010];
int hd[400010], edge[800010][3], tot;
int vis[400010];
queue<int> q;
void add(int x, int y)
{
    tot++;
    edge[tot][0] = x;
    edge[tot][1] = y;
    edge[tot][2] = hd[x];
    hd[x] = tot;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        tot = 0;
        memset(hd, 0, sizeof(hd));
        memset(deg, 0, sizeof(deg));
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            deg[u]++;
            deg[v]++;
            add(u, v);
            add(v, u);
        }
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] <= 1)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            for (int i = hd[x]; i; i = edge[i][2])
            {
                int y = edge[i][1];
                if (vis[y] == 0)
                {
                    deg[y]--;
                    if (deg[y] <= 1)
                    {
                        q.push(y);
                        vis[y] = vis[x] + 1;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i] > k)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
