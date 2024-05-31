#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 300 + 10;
int T;
int n, m, k;
int sx, sy, t;
bool block[maxn][4], vis[maxn];
int dirx[4] = {-1, 1, 0, 0}, diry[4] = {0, 0, 1, -1};
int lim[maxn][4];
int calc(int x, int y)
{
	return x * m + y + 1;
}
queue<pii> q;
void bfs()
{
	memset(vis, 0, sizeof(vis));
	q.push(pii(sx, sy));
	vis[calc(sx, sy)] = true;
	while (!q.empty())
	{
		int ux = q.front().first, uy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int vx = ux + dirx[i], vy = uy + diry[i];
			if (block[calc(ux, uy)][i] || vx < 0 || vx >= n || vy < 0 || vy >= m) continue;
			if (vis[calc(vx, vy)]) continue;
			q.push(pii(vx, vy));
			vis[calc(vx, vy)] = true;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		int x, y;
		scanf("%d%d", &sx, &sy);
		scanf("%d%d", &x, &y);
		t = calc(x, y);
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 4; j++)
				scanf("%d", &lim[i][j]);
		}
		int tot = 1 << k, ans = inf;
		for (int i = 0; i < tot; i++)
		{
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					for (int l = 0; l < 4; l++)
						block[calc(i, j)][l] = false;
			int now = 0;
			for (int j = 0; j < k; j++)
			{
				if (i & (1 << j))
				{
					if (lim[j][0] == lim[j][2])
					{
						if (lim[j][0] == 0 || lim[j][0] == n) continue;
						for (int l = min(lim[j][1], lim[j][3]); l < max(lim[j][1], lim[j][3]); l++)
						{
							block[calc(lim[j][0] - 1, l)][1] = true;
							block[calc(lim[j][0], l)][0] = true;
						}
					}
					else
					{
						if (lim[j][1] == 0 || lim[j][1] == n) continue;
						for (int l = min(lim[j][0], lim[j][2]); l < max(lim[j][0], lim[j][2]); l++)
						{
							block[calc(l, lim[j][1] - 1)][2] = true;
							block[calc(l, lim[j][1])][3] = true;
						}
					}
				}
				else
					now++;
			}
			bfs();
			if (vis[t]) ans = min(now, ans);
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*

2
3 3 3
0 0 0 2
0 1 2 1
0 2 2 2
2 0 2 3

15 15 15
0 0 14 14
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0
*/
