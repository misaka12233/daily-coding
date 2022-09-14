#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
struct node{
	int s, t;
}a[maxn];
bool cmp(node x, node y)
{
	return x.s > y.s;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].s, &a[i].t);
	sort(a + 1, a + n + 1, cmp);
	puts("");
	for (int i = 1; i <= n; i++)
	printf("%d %d\n", a[i].s, a[i].t);
	int now = inf, ans = 0;
	puts("");
	for (int i = 1; i <= n; i++)
	{
		if (a[i].t <= now)
		{
			ans++;
			now = a[i].s;
			printf("%d %d\n", a[i].s, a[i].t);
		}
	}
	printf("%d\n", ans);
	return 0;
}
/*
99 100
98 99
97 98
93 94
91 93
90 91
89 90
86 89
84 86
83 84
77 80
74 77
72 73
66 68
61 66
60 61
59 60
55 59
52 54
51 52
49 50
46 49
45 46
41 44
37 39
35 36
34 35
31 32
27 29
22 27
20 22
18 19
17 18
15 17
13 15
8 13
3 6
37
*/
