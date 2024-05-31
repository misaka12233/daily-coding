#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int T;
int n, m;
void sol()
{
	scanf("%d%d", &n, &m);
	if (n & 1)
	{
		for (int j = 0; j < m; j++)
		{
			if (j & 1) printf("o");
			else printf("x");
		}
		printf("\n");
		n--;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			int t1 = i & 1, t2 = (j / 4) & 1;
			if (t1 ^ t2) printf("x");
			else printf("o");
		}
		printf("\n");
	}
} 
int main()
{
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

