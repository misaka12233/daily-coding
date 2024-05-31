#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
int n;
int calc(int x)
{
	return ((x - 1) | (n - x)) & 1;
}
int sol()
{
	int r, g, b;
	scanf("%d%d%d%d", &n, &r, &g, &b);
	r = calc(r);
	g = calc(g);
	b = calc(b);
	return r ^ g ^ b;
}
int main()
{
	scanf("%d", &T);
	while (T--) 
	{
		if (sol()) puts("Alice");
		else puts("Bob");
	}
	return 0;
}

