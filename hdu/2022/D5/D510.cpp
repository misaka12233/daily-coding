#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int cnt[7], tot[7];
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= 6; i++) 
		tot[i] = 0;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 1; i <= 6; i++)
			cnt[i] = 0;
		bool diff = true;
		for (int i = 1; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			if (cnt[x] != 0) diff = false;
			cnt[x]++;
		}
		if (!diff)
		{
			for (int i = 1; i <= 6; i++)
				tot[i] += cnt[i];
		}
	}
	bool all0 = true;
	for (int i = 1; i <= 6; i++)
		if (tot[i] != 0) 
			all0 = false;
	if (all0) puts("Just a game of chance.");
	else puts("Win!");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		sol();
	}
	return 0;
}

