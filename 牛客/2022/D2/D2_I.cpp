#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10000 + 10;
int n, k, d;
double X[maxn][60], Y[maxn][60], ans[maxn][60];
double res[60][60];
int main()
{
	scanf("%d%d%d", &n, &k, &d);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			scanf("%lf", &X[i][j]);
	for (int i = 1; i <= n; i++)
	{
		double t = 0;
		for (int j = 1; j <= k; j++) t += X[i][j] * X[i][j];
		t = sqrt(t);
		for (int j = 1; j <= k; j++) X[i][j] /= t;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			scanf("%lf", &Y[i][j]);
	for (int i = 1; i <= k; i++)
		for (int j = 1; j <= d; j++)
			for (int l = 1; l <= n; l++)
				res[i][j] += X[l][i] * Y[l][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= d; j++)
			for (int l = 1; l <= k; l++)
				ans[i][j] += X[i][l] * res[l][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= d; j++)
			printf("%.6f ", ans[i][j]);
		puts("");
	}
	return 0;
}

