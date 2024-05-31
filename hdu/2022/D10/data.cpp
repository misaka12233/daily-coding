#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	srand(time(0));
	puts("10");
	int n = 1000000000;
	int m = 100000;
	for (int k = 1; k <= 10; k++)
	{
		printf("%d %d\n", n, m);
		for (int i = 1; i <= m; i++)
			printf("%d %d\n", rand() * rand() % n + 1, rand() * rand() % n + 1);
	}
	return 0;
}

