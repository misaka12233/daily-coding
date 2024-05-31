#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int maxn = 3000 + 10;
int T;
int n, m;
int f[maxn][maxn];
int a[maxn], rk[maxn];
void addeq(int &x, int y)
{
	x = (x + y) % mod;
}
int add(int x, int y)
{
	return (x + y) % mod;
}
void sol()
{
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	m = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != a[i - 1]) m++;
		rk[i] = m;
	}
	f[0][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		int res = 0;
		f[i][rk[i]] = 0;
		for (int j = rk[i - 1]; j <= rk[i]; j++)
			addeq(f[i][rk[i]], f[i - 1][j]);
		addeq(res, f[i][rk[i]]);
		for (int j = rk[i] + 1; j <= rk[n]; j++)
		{
			f[i][j] = add(f[i - 1][j], f[i][j - 1]);
			addeq(res, f[i][j]);
		}
		printf("%d\n", res);
	}
}
int main()
{
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

