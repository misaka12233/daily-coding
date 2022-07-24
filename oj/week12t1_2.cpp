#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n;
int r[maxn], d[maxn];
vector<int> ans[maxn];
bool vis[maxn];
void dfs(int x, int h)
{
    if (x == 0) return;
    ans[h].push_back(x);
    dfs(d[x], h + 1);
    dfs(r[x], h);
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", d + i, r + i);
        vis[d[i]] = true;
        vis[r[i]] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i, 1);
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ans[i].empty()) break;
        for (auto j : ans[i])
            printf("%d ", j);
        puts("");
    }
    return 0;
}