#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10 + 10;
int ans[maxn][maxn];
bool row[maxn][maxn], column[maxn][maxn], block[maxn][maxn];
int T;
void Update(int x, int y, int t, bool type)
{
	row[x][t] = type;
	column[y][t] = type;
	block[(x / 3) * 3 + y / 3][t] = type;
}
bool dfs(int x, int y)
{
	if (x == 9 && y == 0)
		return true;
	if (ans[x][y] != 0)
		return dfs(x + (y + 1) / 9, (y + 1) % 9);
	for (int i = 1; i <= 9; i++)
	{
		if (row[x][i] || column[y][i] || block[(x / 3) * 3 + y / 3][i])
			continue;
		ans[x][y] = i;
		Update(x, y, i, true);
		if (dfs(x + (y + 1) / 9, (y + 1) % 9))
			return true;
		ans[x][y] = 0;
		Update(x, y, i, false);
	}
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		memset(block, 0, sizeof(block));
		for (int i = 0; i < 9; i++)
		{
			char c;
			c = getchar();
			for (int j = 0; j < 9; j++)
			{
				c = getchar();
				ans[i][j] = c - '0';
				Update(i, j, ans[i][j], true);
			}
		}
		if(dfs(0, 0))
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					printf("%d", ans[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}

