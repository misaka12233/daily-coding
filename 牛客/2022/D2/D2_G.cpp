#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int T;
int a[maxn], n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int k = ceil(sqrt(n));
		for (int i = 1; i <= n; i += k)
		{
			for (int j = 1; j <= k && i + j - 1 <= n; j++)
			{
				a[i + j - 1] = min(n - j + 1, i + k - j);
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d ", a[i]);
		puts("");
	}
	return 0;
}

