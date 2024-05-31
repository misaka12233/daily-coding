#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
const int mod = 998244353;
int n;
int ans = 1;
int main()
{
	scanf("%d", &n);
	if (n == 1) puts("1");
	else
	{
		for (int i = 2; i < n; i++)
		{
			ans = 1ll * ans * n % mod;
			ans = 1ll * ans * i % mod;
		}
		printf("%d\n", ans);
	}
	return 0;
}

