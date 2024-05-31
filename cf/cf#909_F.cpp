#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
int n, q;
void sol()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
		printf("%d %d\n", i, i + 1);
	int link = n - 1, x;
	while (q--)
	{
		scanf("%d", &x);
		if (link == n - x)
			puts("-1 -1 -1");
		else
			printf("%d %d %d\n", n, link, n - x);
		link = n - x;
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

