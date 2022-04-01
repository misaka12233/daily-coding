#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
int pow2[25];
int main()
{
	pow2[0] = 1;
	for (int i = 1; i <= 20; i++)
	pow2[i] = pow2[i - 1] << 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int k;
		for (int i = 0; i < 20; i++)
		{
			if (pow2[i] <= n - 1 && n - 1 < pow2[i + 1])
			{
				k = pow2[i];
				break;
			}
		}
		int now = (n - k) & 1;
		for (int i = k; i < n; i++, now ^= 1)
		{
			if (!now) printf("%d %d ", i - k, i);
			else printf("%d %d ", i, i - k);
		}
		for (int i = n - k; i < k; i++)
			printf("%d ", i);
		puts("");
	}
	return 0;
}

