#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
const int mod = 998244353;
int w, h, k;
int f[1000][1000][6];
int main()
{
	scanf("%d%d%d", &w, &h, &k);
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
			f[i][j][1] = 1;
	for (int l = 2; l <= k; l++)
	{
		for (int i = 1; i <= w; i++)
		{
			for (int j = 1; j <= h; j++)
			{
				for (int left = 1; left < l; left++)
				{
					for (int t = 1; t < i; t++)
						f[i][j][l] = (f[i][j][l] + 1ll * f[t][j][left] * f[i - t][j][l - left] % mod) % mod;
					for (int t = 1; t < j; t++)
						f[i][j][l] = (f[i][j][l] + 1ll * f[i][t][left] * f[i][j - t][l - left] % mod) % mod;
				}
			}
		}
	}
	printf("%d\n", f[w][h][k]);
	return 0;
}

