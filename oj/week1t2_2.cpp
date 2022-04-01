#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n;
int a[maxn], suf_gcd[maxn];
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	for (int i = n; i >= 1; i--)
		suf_gcd[i] = gcd(a[i], suf_gcd[i + 1]);
	int ans = 0, pre = 0;
	for (int i = 1; i <= n; pre = gcd(a[i], pre), i++)
		ans = max(ans, gcd(suf_gcd[i + 1], pre));
	printf("%d\n", ans);
	return 0;
}

