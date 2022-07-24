#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
const int mod = 998244353;
typedef long long ll;
int n;
ll ans;
int pos[maxn];
int head[maxn], tot;
bool vis[maxn];
struct node{
    int ed;
    int nxt;
}edge[maxn << 1];
void add(int x, int y)
{
    tot++;
    edge[tot].ed = y;
    edge[tot].nxt = head[x];
    head[x] = tot;
}
int dfs(int x)
{
    vis[x] = true;
    for (int i = head[x]; i; i = edge[i].nxt)
    {
        int y = edge[i].ed;
        if (vis[y]) continue;
        return dfs(y) + 1;
    }
    return 1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        pos[x] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        add(i, pos[x]);
        add(pos[x], i);
    }
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ll val = dfs(i);
            val = val * (val - 1) / 2;
            val = (val + 1) % mod;
            ans = ans * val % mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}