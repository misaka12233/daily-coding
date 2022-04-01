#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n, k;
int x[maxn];
int ans; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		scanf("%d", x + i);
		int cnt[2], p = 1;
		ans = 0;
		for (int i = 1; i <= k; i++, p <<= 1)
		{
			cnt[0] = cnt[1] = 0;
			for (int j = 1; j <= n; j++)
			{
				cnt[x[j] & 1]++;
				x[j] >>= 1;
			}
			if(cnt[0] < cnt[1]) ans += p;
		}
		printf("%d\n", ans);
	}
	return 0;
}

