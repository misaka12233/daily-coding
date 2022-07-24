#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n, k;
int a[maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			scanf("%d", a + i);
		for (int i = 1; i <= n; i++)
		{
			if (a[i] > a[i - 1] + a[i + 1] && i > 1 && i < n)
				cnt++;
		}
		if (k == 1) printf("%d\n", (n - 1) / 2);
		else printf("%d\n", cnt);
	}
	return 0;
}

