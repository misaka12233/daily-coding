#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
bool ans[maxn];
int cnt;
int cnt_gcd(int x, int y)
{
	int res = 0;
	while (y != 0)
	{
		res += x / y;
		x = x % y;
		swap(x, y);
	}
	return res;
}
void strange_gcd(int x, int y)
{
	while (y != 0)
	{
		while (x - y > y)
		{
			x -= y;
			ans[++cnt] = false;
		}
		x -= y;
		ans[++cnt] = true;
		swap(x, y);
	}
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int p, q;
		cnt = 0;
		scanf("%d%d", &p, &q);
		if (cnt_gcd(q, p) > q) puts("Noooooooo!");
		else
		{
			strange_gcd(q, p);
			for (int i = cnt; i >= 1; i--)
			{
				putchar('t');
				if (ans[i]) putchar('c');
				else putchar('s');
			}
			puts("");
		}
	}
	return 0;
}

