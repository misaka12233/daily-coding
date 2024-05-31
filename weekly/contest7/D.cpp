#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int n, p, mod;
int f[maxn][maxn];
int main()
{
	scanf("%d%d%d", &n, &p, &mod);
	int s = n - p;
	f[0][0] = 1;
	for (int k = 1; k <= s; k++)
		for (int i = k; i <= s; i++)
			for (int j = 0; j <= 500; j++)
				f[i][j] = (f[i][j] + f[i - k][j ^ k]) % mod;
	printf("%d\n", f[s][p]);
	return 0;
}

