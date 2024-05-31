#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int a[maxn][maxn];
int ans[maxn];
bool check(int n)
{
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			if ((ans[i] | ans[j]) != a[i][j])
				return false;
	return true;
}
void sol()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		ans[i] = (1 << 30) - 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &a[i][j]);
			if (i != j)
			{
				ans[i] &= a[i][j];
				ans[j] &= a[i][j];
			}
		}
	}
	if (n == 1)
		printf("YES\n0\n");
	else if (n == 2)
		printf("YES\n%d 0\n", a[1][2]);
	else
	{
		if (check(n))
		{
			printf("YES\n");
			for (int i = 1; i <= n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
		else
			printf("NO\n");
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

