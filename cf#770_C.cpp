#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int T;
int n, k;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		if (n % 2 != 0 && k != 1) puts("NO");
		else
		{
			puts("YES");
			int cnt = 1;
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= k; j++, cnt += 2)
				printf("%d ", cnt);
				puts("");
				if (cnt > n * k) cnt = 2;
			}
		}
	}
	return 0;
}

