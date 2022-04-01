#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
bool area[maxn][maxn];
int n, m, ans;
int l[maxn][maxn], r[maxn][maxn], height[maxn][maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			char tmp[3];
			scanf("%s", tmp);
			if (tmp[0] == 'F')
			{
				area[i][j] = true;
				l[i][j] = r[i][j] = j;
				height[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (area[i][j] && area[i][j - 1])
				l[i][j] = l[i][j - 1];
	for (int i = 1; i <= n ; i++)
		for (int j = m; j >= 1; j--)
			if (area[i][j] && area[i][j + 1])
				r[i][j] = r[i][j + 1];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (area[i][j]&&area[i - 1][j])
			{
				height[i][j] = height[i - 1][j] + 1;
				l[i][j] = max(l[i][j], l[i - 1][j]);
				r[i][j] = min(r[i][j], r[i - 1][j]);
			}
			ans = max(ans, (r[i][j] - l[i][j] + 1) * height[i][j]);
		}
	}
	printf("%d\n", 3 * ans);
	return 0;
}

