#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
typedef unsigned int ui;
ui S[maxn];
int n, q;
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int m;
		scanf("%d", &m);
		for (int j = 1; j <= m; j++)
		{
			int x;
			scanf("%d", &x);
			S[i] |= 1 << x;
		}
	}
	scanf("%d", &q);
	while (q--)
	{
		int x, y;
		ui ans;
		char op[4];
		scanf("%d%s%d", &x, op, &y);
		if (op[0] == '/')
			ans = S[x] & S[y];
		else if (op[0] == '-')
			ans = (S[x] | S[y]) ^ S[y];
		else
			ans = S[x] | S[y];
		for (int i = 0; ans; i++, ans >>= 1)
			if (ans & 1)
				printf("%d ", i);
		puts("");
	}
	return 0;
}

