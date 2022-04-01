#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 150000 + 10;
int T;
int n;
int a[maxn], pos[maxn];
int ans;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		scanf("%d", a + i), pos[a[i]] = -1;
		int ans = -1;
		for (int i = 1; i <= n; i++)
		{
			if (pos[a[i]] != -1)
				ans = max(ans, pos[a[i]] + n - i);
			pos[a[i]] = i;
		}
		printf("%d\n", ans);
	}
	return 0;
}

