#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
int a[maxn][maxn];
bool check()
{
	for (int i = 1; i <= n + 1; i++)
	{
		if (a[i][1] == 0) return false;
		if (a[n + 1][i] == 2) return false;
		if (a[i][i] == 1) return false;
	}
	for (int i = 2; i <= n + 1; i++)
	{
		for (int j = 1; j < i; j++)
			if ((a[i][j] + a[i][j + 1] + a[i - 1][j]) % 3 == 0) return false;
		for (int j = 2; j < i; j++)
			if ((a[i][j] + a[i - 1][j] + a[i - 1][j - 1]) % 3 == 0) return false;
	}
	return true;
}
void dfs(int x, int y)
{
	if (x == n + 2)
	{
		if (check())
		{
			for (int i = 1; i <= n + 1; i++)
			{
				for (int j = 1; j <= i; j++)
				printf("%d ", a[i][j]);
				puts("");
			}
		}
		return;
	} 
	for (int i = 0; i < 3; i++)
	{
		if (y == 1 && i == 0) continue;
		if (x == n + 1 && i == 2) continue;
		if (x == y && i == 1) continue;
		a[x][y] = i;
		if (x == y) dfs(x + 1, 1);
		else dfs(x, y + 1);
	}
}
int main()
{
	//memset(a, 0x3f, sizeof(a));
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		puts("No");
	}
	//dfs(1, 1);
	return 0;
}

