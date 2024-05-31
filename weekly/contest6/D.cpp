#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int d, s;
int g[maxn], r[maxn]; 
int gcd(int x, int y)
{
	if (y == 0) return x;
	return gcd(y, x % y);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", g + i, r + i);
		d = gcd(r[i], d);
		s += g[i];
	}
	return 0;
}

