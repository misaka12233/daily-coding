#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n;
int a[maxn];
int cnt[maxn][3][3];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	long long ans = 0; 
	for (int i = 1; i <= n; i++)
	{
		if (a[i] % 3 == 0)
		{
			for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++)
				cnt[i][x][y] = cnt[i - 1][x][y];
			cnt[i][0][0]++;
		}
		else if (a[i] % 3 == 1)
		{
			for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++)
					cnt[i][x][y] = cnt[i - 1][(x + 2) % 3][y];
			cnt[i][1][0]++;
		}
		else if (a[i] % 3 == 2)
		{
			for (int x = 0; x < 3; x++)
				for (int y = 0; y < 3; y++)
					cnt[i][x][y] = cnt[i - 1][x][(y + 2) % 3];
			cnt[i][0][1]++;
		}
		ans = ans + cnt[i][0][0];
		ans = ans + cnt[i][0][1];
		ans = ans + cnt[i][1][0];
	}
	printf("%lld\n", ans);
	return 0;
}

