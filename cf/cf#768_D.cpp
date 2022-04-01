#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n, k;
int a[maxn];
int sort_a[maxn];
int ansx, ansy;
bool check(int len)
{
	int sum = (n - k + 1) / 2 + k;
	for (int i = 1; i + sum - 1 <= n; i++)
	{
		if (sort_a[i + sum - 1] - sort_a[i] <= len)
		{
			ansx = sort_a[i];
			ansy = sort_a[i + sum - 1];
			return true;
		}
	}
	return false;
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		scanf("%d", a + i), sort_a[i] = a[i];
		sort(sort_a + 1, sort_a + n + 1);
		int l = 0, r = sort_a[n] - sort_a[1], mid;
		while (l < r)
		{
			mid = l + r >> 1;
			if (check(mid)) r = mid;
			else l = mid + 1;
		}
		check(l);
		printf("%d %d\n", ansx, ansy);
		l = 1, r = 1;
		int cnt_in = 0, cnt_out = 0, cnt = 0;
		while (cnt < k - 1)
		{
			if (ansx <= a[r] && a[r] <= ansy) cnt_in++;
			else cnt_out++;
			if (cnt_in > cnt_out)
			{
				cnt++;
				printf("%d %d\n", l, r);
				cnt_in = cnt_out = 0;
				l = r + 1;
			}
			r++;
		}
		printf("%d %d\n", l, n);
	}
	return 0;
}

