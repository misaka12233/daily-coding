#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	srand(time(0));
	puts("2");
	int T = 2;
	while (T--)
	{
		int n = 4, m = 10;
		printf("%d %d\n", n, m);
		for (int i = 1; i <= n; i++)
			printf("%d %d\n", rand() % 8, rand() % 8);
		for (int i = 1; i <= m; i++)
			printf("%d\n", rand());
	}
	return 0;
}

