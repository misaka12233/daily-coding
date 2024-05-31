#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000 + 10;
int n;
double calc(int k)
{
	return -1.0 * k / n * log(1.0 * k / n) / log(exp(1)); 
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		if (n <= 2) puts("0");
		else
		{
			int res = 1.0 * n / exp(1);
			int best = 1;
			for (int i = res - 2; i <= res + 2; i++)
			{
				if (i > 0)
				{
					if (calc(i) > calc(best))
						best = i;
				}
			}
			printf("%d\n", best); 
		}
	} 
	return 0;
}

