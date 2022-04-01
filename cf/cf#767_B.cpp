#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int l, r, k;
int getodd(int x)
{
	return (x + 1) / 2;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &l, &r, &k);
		int sum = getodd(r) - getodd(l - 1);
		if (l == r)
		{
			if (l != 1) puts("YES");
			else puts("NO");
		}
		else
		{
			if (k >= sum) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}

