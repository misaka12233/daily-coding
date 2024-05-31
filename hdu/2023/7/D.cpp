#include<bits/stdc++.h>
using namespace std;
int calc(int x)
{
	return 2 * x * (x / 2 + 1) + x;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, l, r, mid;
		scanf("%d", &n);
		l = 1, r = sqrt(n);
		while (l < r)
		{
			mid = l + r >> 1;
			if (calc(mid) >= n) r = mid;
			else l = mid + 1;
		}
		printf("%d\n", l);
	}
	return 0;
}

