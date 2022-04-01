#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int n;
int a[maxn];
bool f[maxn];
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main()
{
	scanf("%d", &n);
	int mx = 0;
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i), mx = max(mx, a[i]), f[a[i]] = true;
	for (int i = mx; i >= 1; i--)
	{
		int now = 0;
		for (int j = i; j <= mx; j += i)
		{
			if (f[j]) now = gcd(j, now);
			if (now == i)
			{
				f[i] = true;
				break;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= mx; i++)
		if (f[i])
			cnt++;
	printf("%d\n", cnt - n);
	return 0;
}

