#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 30 + 5;
const int maxv = 900000;
int n;
int a[maxn];
int f[maxv + 10];
int main()
{
	scanf("%d%d", &a[1], &a[2]); 
	for (int i = 1; i <= maxv; i++) f[i] = -1;
	for (int i = 1; i <= 2; i++)
	{
		for (int j = a[i]; j <= maxv; j++)
		{
			if (f[j - a[i]] != -1)
			{
				if (f[j] != -1) f[j] = min(f[j], f[j - a[i]] + 1);
				else f[j] = f[j - a[i]] + 1;
			}
		}
	}
	for (int i = maxv; i >= 1; i--)
	{
		if (f[i] == -1)
		{
			printf("%d\n", i);
			break;
		}
	}
	if (f[858201] != -1) puts("hack");
	return 0;
}

