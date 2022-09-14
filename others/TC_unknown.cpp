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
vector<int> over[maxn];
bool vis[maxn];
node res[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].s, &a[i].t);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == i) continue;
			if (a[i].s < a[j].t && a[j].s < a[i].t)
				over[i].push_back(j);
		}
	}
	bool end;
	int ans = 0;
	puts("");
	while (1)
	{
		end = true;
		int mn = inf, now;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && mn > over[i].size())
			{
				end = false;
				now = i;
				mn = over[i].size();
			}
		}
		if (end) break;
		ans++;
		for (auto x : over[now])
			vis[x] = true;
		vis[now] = true;
		res[ans] = a[now];
	}
	sort(res + 1, res + ans + 1, cmp);
	for (int i = 1; i <= ans; i++)
	printf("%d %d\n", res[i].s, res[i].t);
	printf("%d\n", ans);
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
26 28
20 22
18 19
17 18
15 17
13 15
7 13
3 6
36
*/
