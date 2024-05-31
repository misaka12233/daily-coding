#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, x;
int ans;
int q[maxn];
int st, ed;
int main()
{
	scanf("%d%d", &n, &x);
	st = 1, ed = 0;
	for (int i = 1; i <= n; i++)
	{
		ed++;
		scanf("%d", q + ed);
		if (ed > 1 && (q[ed] == q[ed - 1] || q[ed] + q[ed - 1] == x))
		{
			ans++;
			ed -= 2;
		}
	}
	while (st < ed && (q[st] == q[ed] || q[st] + q[ed] == x))
	{
		ans++;
		ed--;
		st++;
	}
	printf("%d\n", ans);
	return 0;
}
/*
12 5
2 1 2 5 2 1 2 3 4 8 4 3
*/
