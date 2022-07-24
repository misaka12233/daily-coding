#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n;
int b[6], m;
bool check(int x)
{
	for (int i = 1; i <= m; i++)
		if (x == b[i])
			return true;
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		int cnt0 = 0, cnt1 = 0, x; 
		bool ans = true, have0 = false;
		m = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (!ans) continue;
			if (x < 0)
			{
				if (cnt0 == 2)
				{
					ans = false;
					continue;
				}
				cnt0++;
				b[++m] = x;
			}
			else if (x > 0)
			{
				if (cnt1 == 2)
				{
					ans = false;
					continue;
				}
				cnt1++;
				b[++m] = x;
			}
			else if (!have0)
			{
				b[++m] = 0;
				have0 = true;
			}
		}
		for (int i = 1; i + 2 <= m; i++)
		{
			for (int j = i + 1; j + 1 <= m; j++)
			{
				for (int k = j + 1; k <= m; k++)
				{
					int x = b[i] + b[j] + b[k];
					if (!check(x))
					{
						ans = false;
						break;
					} 
				}
				if (!ans) break;
			}
			if (!ans) break;
		}
		if (ans) puts("YES");
		else puts("NO");
	}
	return 0;
}

