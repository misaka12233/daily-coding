#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 5000 + 10;
int f[maxn], vis[maxn];
int main()
{
	f[0] = 0;
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= 5000; i++)
	{
		for (int j = 0; j <= i; j++)
			vis[j] = 0;
		for (int j = 2; j <= i; j++)
			vis[f[j - 2] ^ f[i - j]] = 1;
		for (int j = 0; j <= i; j++)
			if (vis[j] == 0)
			{
				f[i] = j;
				break;
			}
	}
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n;
		scanf("%d", &n);
		if (f[n] != 0)
			puts("First");
		else
			puts("Second");
	}
	return 0;
}

