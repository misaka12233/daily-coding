#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n, k;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		if (k == n - 1)
		{
			if (n == 4) puts("-1");
			else
			{
				int p;
				for (p = 1; p < n / 2; p <<= 1)
					printf("%d %d\n", p, (p << 1) ^ (n - 1));
				printf("%d %d\n", p, 1 ^ (n - 1));
				printf("%d %d\n", 0, n - 1);
				for (int i = 1; i < n / 2; i++)
				{
					if (i != (i & -i) && i != n / 2 - 1)
						printf("%d %d\n", i, i ^ (n - 1));
				}
			}
		}
		else
		{
			printf("%d %d\n", 0, k ^ (n - 1));
			if (k != 0)
			printf("%d %d\n", k, n - 1);
			for (int i = 1; i < n / 2; i++)
			{
				if (i != k && i != (k ^ (n - 1)))
					printf("%d %d\n", i, i ^ (n - 1));
			}
		}
	}
	return 0;
}

