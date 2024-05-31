#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int cnt[maxn];
void sol()
{
	int n;
	memset(cnt, 0, sizeof(cnt));
	scanf("%d", &n);
	int f2 = -1, f3 = -1;
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		cnt[x]++;
		if (f3 == -1)
		{
			if (cnt[x] == 2)
				f3 = i;
		}
		else if (f2 == -1)
		{
			if (cnt[x] == 2)
				f2 = i;
		}
	}
	if (f2 == -1 || f3 == -1) puts("-1");
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (i == f2)
				printf("2 ");
			else if (i == f3)
				printf("3 ");
			else 
				printf("1 "); 
		}
		printf("\n");
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

