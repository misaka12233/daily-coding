#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int a[maxn];
void sol()
{
	int n;
	scanf("%d", &n);
	if (n == 3) puts("NO");
	else
	{
		puts("YES");
		int x = n / 2, y = n - x;
		if (x == 1) x++, y++;
		for (int i = 1; i <= n; i++)
			printf("%d ", (i & 1) ? (x - 1) : -(y - 1));
		putchar('\n');
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

