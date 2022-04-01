#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			for (int k = n; k > i; k--)
			printf("%d ", k);
			printf("1 ");
			for (int k = i; k >= 2; k--)
			printf("%d ", k);
			puts("");
		}
	}
	return 0;
}

