#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
struct node{
	int t;
	int x;
}a[maxn << 1];
int n;
bool cmp(node x, node y)
{
	return x.x < y.x;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i].t = 0;
		a[i].x = x;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		a[i + n].t = 1;
		a[i + n].x = x;
	}
	n = n * 2;
	sort(a + 1, a + n + 1, cmp);
	int maxl = 0, maxr = 0;
	int cnt[2];
	cnt[0] = 0;
	cnt[1] = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[a[i].t]++;
		if (a[i].t == 0 && maxl < cnt[1])
			maxl++;
	}
	cnt[0] = 0;
	cnt[1] = 0;
	for (int i = n; i >= 1; i--)
	{
		cnt[a[i].t]++;
		if (a[i].t == 0 && maxr < cnt[1])
			maxr++;
	}
	printf("%d\n", maxl - (n / 2 - maxr) + 1);
	for (int i = n / 2 - maxr; i <= maxl; i++)
		printf("%d ", i);
	return 0;
}

