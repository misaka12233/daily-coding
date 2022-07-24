#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		int n, x;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &x);
		printf("%d\n", x);
	}
	return 0;
}

