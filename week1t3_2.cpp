#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
const int mod = 1e9 + 7;
int n;
int f[maxn][maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	f[i][0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			f[i][j] = (f[i][j - 1] + f[i - 1][j] >= mod) ? f[i][j - 1] + f[i - 1][j] - mod : f[i][j - 1] + f[i - 1][j];
	printf("%d\n", f[n][n]);
	return 0;
}

