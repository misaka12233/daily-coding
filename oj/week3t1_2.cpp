#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2000000 + 10;
int T;
int n, k;
int a[maxn]; 
long long fac[20];
void my_next_per(int l, int r)
{
	next_permutation(a + l, a + r + 1);
	return;
}
int main()
{
	scanf("%d", &T);
	fac[0] = 1;
	for (long long i = 1; i <= 12; i++)
	fac[i] = fac[i - 1] * i;
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		a[n + 1] = 0;
		if (n <= 12) k = k % fac[n];
		if (k != 0)
		{
			int pos = 1;
			for (int i = n - 1; i >= 1; i--)
			{
				if (a[i] < a[i + 1])
				{
					if (n - i + 1 > 13)
					{
						my_next_per(1, n);
						k--;
						pos = i + 1;
						break;
					}
					else
					{
						int j;
						for (j = i + 1; j <= n; j++)
						{
							if (a[j + 1] < a[i])
								break;
						}
						while (k >= fac[n - i] && j != i)
						{
							swap(a[i], a[j]);
							j--;
							k -= fac[n - i];
						}
						if (k == 0) break;
						if (k < fac[n - i])
						{
							my_next_per(1, n);
							k--;
							pos = i + 1;
							break;
						}
					}
				}
			}
			if (pos == 1 && k > 0)
				my_next_per(1, n), k--;
		}
		for (int i = n - min(n, 13) + 1; i < n; i++)
		{
			int j = i + 1;
			while (k >= fac[n - i] && j != i)
			{
				swap(a[i], a[j]);
				j++;
				k -= fac[n - i];
			}
			if (k == 0) break;
		}
		for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
		puts("");
	}
	return 0;
}

