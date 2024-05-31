#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
struct node{
	int m, p;
};
node a[maxn], b[maxn];
bool cmp1(node x, node y)
{
	if (x.m + x.p == y.m + y.p)
		return x.m > y.m;
	return x.m + x.p > y.m + y.p;
}
bool cmp2(node x, node y)
{
	return x.m > y.m;
}
bool cmp3(node x, node y)
{
	return x.p > y.p;
}
int sol(node *a, int mid)
{
	sort(a + 1, a + mid + 1, cmp2);
	sort(a + mid + 1, a + n + 1, cmp3);
	int l = 1, r = n;
	long long s = 0;
	while (l <= mid && r > mid)
	{
		if (s + a[l].m >= a[r].p)
		{
			s = s + a[l].m - a[r].p;
			l++;
			r--;
		} 
		else break;
	}
	return l - 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i].p);
	sort(a + 1, a + n + 1, cmp1);
	for (int i = 1; i <= n; i++)
		b[i] = a[i];
	printf("%d\n", max(sol(a, n / 2), sol(b, n / 2 + 1)));
	return 0;
}

