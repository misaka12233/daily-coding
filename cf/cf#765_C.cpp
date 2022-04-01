#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int n, m, k;
int a[maxn], d[maxn];
int f[maxn][maxn]; // f[i][j]���ӵ�iλ��ǰ����ɾȥj��·�ƵĴ����� 
int g[maxn][maxn]; // g[i][j]��ǰiλɾȥj��·�Ƶ���������� 
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	scanf("%d", d + i);
	d[n + 1] = m;
	for (int i = 1; i <= n; i++)
	scanf("%d", a + i);
	for (int i = 1; i <= n; i++)
	{
		int sum = 0;
		for (int j = 1; j < i && j <= k; j++)
		{
			sum += d[i - j + 2] - d[i - j + 1];
			f[i][j] = f[i][j - 1] + (a[i - j + 1] - a[i - j]) * sum;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < i && j <= k; j++)
			for (int l = 0; l <= j; l++)
				g[i][j] = max (g[i][j], g[i - l - 1][j - l] + f[i][l]);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	ans += a[i] * (d[i + 1] - d[i]);
	int finalans = ans;
	for (int i = 1; i <= k; i++)
	finalans = min(finalans, ans - g[n][i]);
	printf("%d\n", finalans);
	return 0;
}

