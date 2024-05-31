#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int f[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		f[i] = inf;
		for (int j = 2; j * (j - 1) / 2 <= i; j++)
			f[i] = min(f[i], f[i - j * (j - 1) / 2] + j);
	}
	printf("%d %lld\n", f[n], 1ll * f[n] * (f[n] - 1) / 2 - n);
	return 0;
}

