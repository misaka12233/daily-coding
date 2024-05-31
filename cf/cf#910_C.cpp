#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 20 + 10;
int a[maxn][maxn][2];
void sol()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (k < n + m - 2 || (k - (n + m - 2)) % 2 != 0)
	{
		puts("NO");
		return;
	}
	memset(a, 0, sizeof(a));
	puts("YES");
	a[1][1][0] = 1;
	a[1][1][1] = 2;
	a[1][2][1] = 2;
	a[2][1][0] = 1;
	a[2][1][1] = 2;
	for (int i = 3; i < n; i++)
		a[i][1][1] = 3 - a[i - 1][1][1];
	a[n][1][0] = 3 - a[n - 1][1][1];
	for (int i = 2; i < m; i++)
		a[n][i][0] = 3 - a[n][i - 1][0];
	
	for (int i = 2; i < m; i++)
		a[1][i][0] = 3 - a[1][i - 1][0];
	a[1][m][1] = 3 - a[1][m - 1][0];
	for (int i = 2; i < n; i++)
		a[i][m][1] = 3 - a[i - 1][m][1];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (a[i][j][0] == 0)
				printf("B ");
			else
				printf("%c ", (a[i][j][0] == 1) ? 'B' : 'R');
		}
		printf("\n");
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j][1] == 0)
				printf("B ");
			else
				printf("%c ", (a[i][j][1] == 1) ? 'B' : 'R');
		}
		printf("\n");
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

