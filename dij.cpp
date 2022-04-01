#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n, m, s;
int head[maxn], edge[maxn * 2][3], tot;
int dis[maxn];
bool vis[maxn];
priority_queue<pair<int, int>> q;
int main()
{
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        tot++;
        edge[tot][0] = v;
        edge[tot][1] = w;
        edge[tot][2] = head[u];
        head[u] = tot;
    }
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    q.push(make_pair(-dis[s], s));
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = head[u]; i; i = edge[i][2])
        {
            int v = edge[i][0];
            if (dis[v] > dis[u] + edge[i][1])
            {
                dis[v] = dis[u] + edge[i][1];
                q.push(make_pair(-dis[v], v));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", dis[i]);
    return 0;
}