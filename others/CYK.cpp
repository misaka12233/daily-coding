#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
char symb[10] = "0ABCS";
char s[10] = "0bbabbab";
int a[5][5];
set<int> dp[10][10];
int main()
{
	a[1][3] = 4;
	a[2][3] = 4;
	a[2][1] = 1;
	a[3][1] = 2;
	a[2][2] = 3;
	for (int i = 1; i <= 7; i++)
	{
		if (s[i] == 'a')
			dp[i][i].insert(1);
		else
		{
			dp[i][i].insert(2);
			dp[i][i].insert(3);
		}
	}
	for (int len = 2; len <= 7; len++)
	{
		for (int l = 1; l + len - 1 <= 7; l++)
		{
			int r = l + len - 1;
			for (int k = l; k < r; k++)
			{
				for (auto x : dp[l][k])
				{
					for (auto y : dp[k + 1][r])
					{
						if (a[x][y] != 0)
							dp[l][r].insert(a[x][y]);
					}
				}
			}
		}
	}
	for (int len = 1; len <= 7; len++)
	{
		printf("$");
		for (int l = 1; l + len - 1 <= 7; l++)
		{
			int r = l + len - 1;
			printf("X_{%d%d} = \\{ ", l, r);
			for (auto x : dp[l][r])
			{
				if (x == *dp[l][r].begin())
					printf("%c", symb[x]);
				else
					printf(",%c", symb[x]);
			}
			printf("\\}");
			if (r != 7) printf(",");
		}
		printf("$\n");
	}
	return 0;
}

