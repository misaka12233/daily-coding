#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 20000 + 10;
int main()
{
	int k;
	while (scanf("%d", &k) != EOF)
	{
		for (int i = 0; i <= maxn; i++)
		{
			int sum = k, x = i;
			while (x)
			{
				sum += (x % 10) * (x % 10) * (x % 10);
				x /= 10;
			}
			if (sum == i) printf("%d\n", i);
		} 
		puts("");
	}
	return 0;
}

