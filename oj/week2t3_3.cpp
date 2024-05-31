#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
struct node{
	int x, y;
}a[maxn];
int n;
int f[maxn], ed[maxn];
bool cmp(node x, node y)
{
	if (x.x == y.x) return x.y > y.y;
	return x.x > y.x;
}
int getpre(int x)
{
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (ed[mid + 1] < x) l = mid + 1;
		else r = mid;
	}
	return l;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].x, &a[i].y);
	for (int i = 1; i <= n; i++) ed[i] = inf;
	ed[0] = -inf;
	sort(a + 1, a + n + 1, cmp);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = getpre(a[i].y) + 1;
		ed[f[i]] = min(ed[f[i]], a[i].y);
		ans = max(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}

