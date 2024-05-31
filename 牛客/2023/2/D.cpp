#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2000 + 10;
int T;
int n, m, k;
bool vis[maxn];
int a[maxn][maxn];
void sol()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = (k - 1) % n; k > 0; k--, i = (i - 1 + n) % n)
	{
		int mx = 0;
		for (int j = 1; j <= m; j++)
			if (!vis[j] && a[i][j] > a[i][mx])
				mx = j;
		vis[mx] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		if (vis[i])
		{
			printf("%d ", i);
			vis[i] = false;
		}
	}
	printf("\n");
}
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

