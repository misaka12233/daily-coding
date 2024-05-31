#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 30 + 5;
const int maxv = 7000000;
int n;
int m[105], len;
int ans[105], res, cnt, mn;
int a[maxn];
int f[maxv + 10];
bool add(int x)
{
	bool is_zero = true;
	for (int i = len; i >= 1; i--)
	{
		int now = ans[i] + x;
		ans[i] = ((ans[i] + x) % 10 + 10) % 10;
		if (ans[i] != 0) is_zero = false;
		x = (now - ans[i]) / 10;
	}
	return is_zero;
}
bool sol()
{
	mn = inf;
	if (f[res] != -1) mn = min(mn, f[res] - cnt);
	while (res + a[n] <= maxv)
	{
		res += a[n];
		cnt++;
		if (f[res] != -1) mn = min(mn, f[res] - cnt);
		if (add(-1)) break;
	}
	return mn != inf;
}
int main()
{
	scanf("%d", &n);
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while ('0' <= c && c <= '9')
	{
		m[++len] = c - '0';
		c = getchar();
	}
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= maxv; i++)
		f[i] = -1;
	for (int i = 1; i < n; i++)
	{
		for (int j = a[i]; j <= maxv; j++)
		{
			if (f[j - a[i]] != -1)
			{
				if (f[j] != -1) f[j] = min(f[j], f[j - a[i]] + 1);
				else f[j] = f[j - a[i]] + 1;
			}
		}
	}
	
	for (int i = 1; i <= len; i++)
	{
		res = res * 10 + m[i];
		ans[i] = res / a[n];
		res = res % a[n];
	}
	
	if (sol())
	{
		add(mn);
		add(cnt);
		bool not_zero = false;
		for (int i = 1; i <= len; i++)
		{
			if (ans[i] != 0) not_zero = true;
			if (not_zero) printf("%d", ans[i]);
		}
		putchar('\n');
	}
	else puts("-1");
	return 0;
}

