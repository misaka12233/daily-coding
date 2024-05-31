#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	freopen("MAX_CUT.in", "w", stdout);
	srand(time(0));
	int n = 20;
	printf("%d\n", n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				printf("0 ");
			else
				printf("%d ", rand());
		}
		printf("\n");
	}
	return 0;
}

