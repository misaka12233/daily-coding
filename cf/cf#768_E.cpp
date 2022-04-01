#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int a[maxn];
int fir[maxn], lst[maxn];
int to[maxn];
int getmax(int l, int r)
{
	int mx = l;
	for (int i = l + 1; i <= r; i++)
	{
		if (to[mx] < to[i])
			mx = i;
	}
	return to[mx];
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		if (!fir[a[i]]) 
			fir[a[i]] = i;
	}
	for (int i = n; i >= 1; i--)
	{
		if (!lst[a[i]]) 
			lst[a[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (fir[a[i]] && lst[a[i]])
		to[fir[a[i]]] = lst[a[i]];
	}
	int now = 1, end, ans = 0;
	while (now <= n)
	{
		end = to[now];
		if (end - now > 1)
		{
			ans += end - now - 1;
			int k = getmax(now, end);
			while (k > end)
			{
				ans += k - end - 1;
				int tmp = k;
				k = getmax(end, k);
				end = tmp;
			}
		}
		now = end + 1;
	}
	printf("%d\n", ans);
	return 0;
}

