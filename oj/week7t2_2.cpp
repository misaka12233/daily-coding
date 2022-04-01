#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int mod = 998244353;
int T;
int ans = 0;
int f[maxn];
int main()
{
	scanf("%d", &T);
	f[1] = 1;
	for (int i = 2; i <= 1e5; i++)
	{
		f[i] = i;
		int now = 3, lst = 2;
		while (lst <= i)
		{
			int tmp = i / lst;
			(f[i] += 1ll * f[tmp] * (now - lst) % mod) %= mod;
			lst = now;
			now = i / tmp + 1;
		}
	}
	while (T--)
	{
		int index;
		scanf("%d", &index);
		if (index >= 0) printf("%d\n", f[index]);
		else printf("%d\n", index);
	}
	return 0;
}

