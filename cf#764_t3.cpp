#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
int pow2[maxn];
int a[maxn];
bool vis[maxn];
int main()
{
	pow2[0] = 1;
	for (int i = 1; i <= 30; i++)
		pow2[i] = pow2[i - 1] << 1;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			for (int j = 0; j <= 30; j++)
			{
				if (a[i] / pow2[j] <= n)
				{
					a[i] /= pow2[j];
					break;
				}
			}
		}
		memset(vis, 0, sizeof(vis));
		bool ans = true;
		for (int i = 1; i <= n; i++)
		{
			while (vis[a[i]]) a[i] /= 2;
			if (a[i] == 0)
			{
				ans = false;
				break;
			}
			vis[a[i]] = true;
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}

