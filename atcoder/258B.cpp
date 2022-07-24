#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
long long a[maxn][maxn];
long long n, p[maxn];
int dirx[10] = {0, 0, 1, 1, 1, -1, -1, -1}, diry[10] = {1, -1, 1, -1, 0, 1, -1, 0};
long long ans[10][maxn][maxn];
int main()
{
	int mxx = 0, mxy = 0;
	scanf("%d", &n);
	p[0] = 1;
	for (int i = 1; i < n; i++)
		p[i] = p[i - 1] * 10;
	for (int i = 0; i < n; i++)
	{
		char s[maxn];
		scanf("%s", s);
		for (int j = 0; j < n; j++)
			a[i][j] = s[j] - '0';
	}
	long long res = 0;
	for (int l = 0; l < 8; l++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
					ans[l][i][j] += a[(i + k * dirx[l] + n) % n][(j + k * diry[l] + n) % n] * p[n - k - 1];
				res = max(res, ans[l][i][j]);
			}
		}
	}
	printf("%lld\n", res);
	return 0;
}

