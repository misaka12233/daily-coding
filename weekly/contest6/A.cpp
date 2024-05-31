#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n;
char s[maxn];
int isC[maxn][3];
int f[maxn][3][3];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		for (int j = 0; j < 3; j++)
		{
			if (s[j] == 'A' || s[j] == 'E' || s[j] == 'I' || s[j] == 'O' || s[j] == 'U' || s[j] == 'Y')
				isC[i][j] = 0;
			else
				isC[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				f[i][j][k] = inf;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (isC[i][0] == 1 && k > 0)
					f[i][0][k] = min(f[i][0][k], f[i - 1][j][k - 1] + 1);
				else if (isC[i][0] == 0)
					f[i][0][0] = min(f[i][0][0], f[i - 1][j][k] + 1);
			}
		}
		for (int j = 1; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (isC[i][j] == 1 && k > 0)
					f[i][j][k] = min(f[i][j][k], f[i][j - 1][k - 1] + 1);
				else if (isC[i][j] == 0)
					f[i][j][0] = min(f[i][j][0], f[i][j - 1][k] + 1);
			}
		}
	}
	int ans = inf;
	for (int j = 0; j < 3; j++)
		for (int k = 0; k < 3; k++)
			ans = min(ans, f[n][j][k]);
	if (ans != inf)
		printf("%d\n", ans);
	else
		printf("*\n");
	return 0;
}

