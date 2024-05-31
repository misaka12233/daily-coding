#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int calc(int x)
{
	return 2 * x * (x / 2 + 1) + x;
}
int main()
{
	for (int i = 1; i <= 100; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (calc(j) >= i)
			{
				printf("%d: %d\n", i, j);
				break;
			}
		}
	}
	return 0;
}

