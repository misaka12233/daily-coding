#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int n, m;
bool dp[maxn][maxn][3]; // 0 - win, 1 - draw, 2 - lose
char s[maxn][maxn];
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", s[i] + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				for (int l = 0; l < 3; l++)
					dp[i][j][l] = false;
		for (int i = n; i >= 1; i--)
		{
			for (int j = m; j >= 1; j--)
			{
				if (s[i][j] == 'A')
				{
					dp[i][j][0] = true;
					dp[i][j][1] = dp[i][j][2] = false;
				}
				else if (s[i][j] == 'B')
				{
					dp[i][j][2] = true;
					dp[i][j][0] = dp[i][j][1] = false;
				}
				else if (i == n && j == m)
				{
					dp[i][j][1] = true;
					dp[i][j][0] = dp[i][j][2] = false;
				}
				else
				{
					if ((i + j) & 1)
					{
						for (int l = 0; l < 3; l++)
						{
							if (i == n) 
								dp[i][j][l] = dp[i][j + 1][l];
							else if (j == m) 
								dp[i][j][l] = dp[i + 1][j][l];
							else
								dp[i][j][l] = dp[i + 1][j][l] && dp[i][j + 1][l];
						}
					}
					else
					{
						for (int l = 0; l < 3; l++)
						{
							if (i == n) 
								dp[i][j][l] = dp[i][j + 1][l];
							else if (j == m) 
								dp[i][j][l] = dp[i + 1][j][l];
							else
								dp[i][j][l] = dp[i + 1][j][l] || dp[i][j + 1][l];
						}
					}
				}
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (dp[1][1][i])
				printf("yes ");
			else
				printf("no ");
		}
		puts("");
	}
	return 0;
}

