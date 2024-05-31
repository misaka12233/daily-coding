#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n = 10;
int sg[maxn][maxn];
bool vis[maxn << 1];
int main()
{
	for (int sum = 3; sum <= 2 * n; sum++)
	{
		for (int x = 1; x < sum; x++)
		{
			int y = sum - x;
			if (x > n || y > n) continue;
			for (int i = 0; i <= 2 * n; i++)
				vis[i] = false;
			for (int i = 1; i < x; i++)
				vis[sg[i][x - i]] = true;
			for (int i = 1; i < y; i++)
				vis[sg[i][y - i]] = true;
			for (int i = 0; i <= 2 * n; i++)
			{
				if (!vis[i])
				{
					sg[x][y] = i;
					break;
				}
			}
		}
		for (int i = 0; i <= 2 * n; i++)
			vis[i] = false;
		for (int i = 1; i < sum; i++)
			vis[sg[i][sum - i]] = true;
		for (int i = 2 * n; i >= 0; i--)
		{
			if (vis[i]) putchar('1');
			else putchar('0');
		}
		putchar('\n');
	}
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			printf("%d ", sg[i][j]);
		putchar('\n');
	}
	*/
	return 0;
}

