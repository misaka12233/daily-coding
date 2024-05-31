#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int m, n, k;
int a[maxn], b[maxn];
int getmx(int *x, int len)
{
	int mx = 1;
	for (int i = 1; i <= len; i++)
		if (x[mx] < x[i])
			mx = i;
	return mx;
}
int getmn(int *x, int len)
{
	int mn = 1;
	for (int i = 1; i <= len; i++)
		if (x[mn] > x[i])
			mn = i;
	return mn;
}
void get_a()
{
	int mna = getmn(a, n), mxb = getmx(b, m);
	if (a[mna] < b[mxb])
		swap(a[mna], b[mxb]);
	k--;
	if (k == 0) return;
	int mxa = getmx(a, n), mnb = getmn(b, m);
	swap(a[mxa], b[mnb]);
	k--;
	if (k == 0) return;
	k = k & 1;
	if (k == 0) return;
	mna = getmn(a, n), mxb = getmx(b, m);
	swap(a[mna], b[mxb]);
	return;
}
void sol()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = 1; i <= m; i++)
		scanf("%d", b + i);
	get_a();
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += a[i];
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

