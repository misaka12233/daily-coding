#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int f[maxn][maxn];
int main()
{
	f[0][0] = 0;
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; i + j <= 20; j++)
		{
			if (i >= 1)
				f[i][j] |= (f[i - 1][j + 1] ^ 1) | (f[i - 1][j] ^ 1);
			if (j >= 1)
				f[i][j] |= f[i][j - 1] ^ 1;
			printf("%d ", f[i][j]);
		}
		printf("\n");
	}
	return 0;
}

