#include <bits/stdc++.h>
using namespace std;
const int maxn = 400 + 10;
int n, m;
char s[maxn][maxn];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
struct node{
    int x;
    int y;
    int nxt;
}st[maxn * maxn];
int tot, head;
bool vis[maxn << 1][maxn << 1];
bool chk(int x, int y)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n && s[x][y] == '1');
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%s", s[i] + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i][j] == '1')
            {
                if (tot != 0)
                    st[tot].nxt = tot + 1;
                else   
                    head = tot + 1;
                tot++;
                st[tot].x = i;
                st[tot].y = j;
            }
        }
    }
    int movX = 0, movY = 0, op;
    bool empt = false;
    vis[movX + n][movY + n] = true;
    printf("%d\n", tot);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &op);
        movX += dx[op];
        movY += dy[op];
        if (movX >= n || movX <= -n || movY >= n || movY <= -n) empt = true;
        if (empt)
        {
            puts("0");
            continue;
        }
        if (vis[movX + n][movY + n])
        {
            printf("%d\n", tot);
            continue;
        }
        vis[movX + n][movY + n] = true;
        int lst = 0, now = head;
        while (now != 0)
        {
            if (!chk(st[now].x + movX, st[now].y + movY))
            {
                if (lst == 0)
                    head = st[now].nxt;
                else
                    st[lst].nxt = st[now].nxt;
                tot--;
            }
            else lst = now;
            now = st[now].nxt;
        }
        printf("%d\n", tot);
    }
    return 0;
}