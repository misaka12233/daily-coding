#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int T;
int n, m, cnt;
int initial[maxn];
int a[maxn], gap[maxn]; 
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		scanf("%d", initial + i);
		cnt = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				for (int k = j; k <= n; k++)
					a[++cnt] = initial[i] + initial[j] + initial[k];
		sort(a + 1, a + cnt + 1);
		for (int i = 1; i <= cnt; i++)
		gap[cnt - i + 1] = m - a[i];
		bool ans = false;
		for (int i = 1, j = 1; j <= cnt; j++)
		{
			while (a[i] < gap[j] && i + 1 <= cnt) i++;
			if (a[i] == gap[j] && cnt - i + 1 != j) 
			{
				ans = true;
				break;
			}
		}
		if (ans) puts("Yes");
		else puts("No");
	}
	return 0;
}

