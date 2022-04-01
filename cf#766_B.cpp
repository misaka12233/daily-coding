#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int T;
int n, m;
int maxdis[maxn], cnt;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				maxdis[++cnt] = max(i - 1, n - i) + max(j - 1, m - j);
		sort(maxdis + 1, maxdis + cnt + 1);
		for (int i = 1; i <= cnt; i++)
			printf("%d ", maxdis[i]);
		puts("");
	}
	return 0;
}

