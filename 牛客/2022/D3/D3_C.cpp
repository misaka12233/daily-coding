#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 2000000 + 10;
int n;
char s[maxn * 10];
char ans[maxn * 10];
struct node{
	int l, r;
};
node t[maxn];
bool cmp(node a, node b)
{
	int i = a.l, j = b.l;
	bool tob, toa;
	tob = toa = false;
	while (s[i] == s[j])
	{
		i++, j++;
		if (tob && i > b.r) return false;
		if (!tob && i > a.r)
		{
			i = b.l;
			tob = true;
		}
		if (!toa && j > b.r)
		{
			j = a.l;
			toa = true;
		}
	}
	return s[i] < s[j];
}
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	scanf("%d", &n);
	int now = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s + now);
		int len = strlen(s + now);
		t[i].l = now;
		t[i].r = now + len - 1;
		now += len;
	}
	sort(t + 1, t + n + 1, cmp);
	int m = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = t[i].l; j <= t[i].r; j++, m++)
			ans[m] = s[j];
	}
	printf("%s\n", ans);
	return 0;
}

