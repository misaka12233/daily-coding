#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10;
const int mod = 998244353;
int n, m, cnt1, cnt2;
struct node{
	int a[maxn];
	bool operator < (const node &b) const
	{
		for (int i = 1; i <= n; i++)
			if (a[i] != b.a[i]) 
				return a[i] < b.a[i];
		return false;
	}
};
map<node, bool> mp;
node now;
bool dfs()
{
	if (mp.count(now)) return mp[now];
	bool res = false, cando = false;
	for (int i = 1; i <= n; i++)
	{
		int origin = now.a[i];
		for (int j = now.a[i - 1]; j < now.a[i]; j++)
		{
			now.a[i] = j;
			res |= dfs() ^ 1;
			now.a[i] = origin;
			cando = true;
		}
	}
	if (!cando) mp[now] = false;
	else mp[now] = res;
	return mp[now];
}
void getans(int x, int lst)
{
	if (x == n + 1)
	{
		for (int i = 1; i <= n; i++)
			printf("%d ", now.a[i]);
		if (dfs()) printf("A\n"), cnt1++;
		else printf("B\n"), cnt2++;
		return;
	}
	for (int i = m; i >= lst; i--)
	{
		now.a[x] = i;
		getans(x + 1, i);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	getans(1, 0);
	printf("%d %d\n", cnt1, cnt2);
	return 0;
}

