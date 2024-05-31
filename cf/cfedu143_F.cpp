#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, k;
int st[maxn];
int len[maxn]; 
vector<int> e[maxn];
int f[maxn], g[maxn];
bool dfs(int x, int fa)
{
	int out = 0, in = 0;
	for (int y : e[x])
	{
		if (y == fa) continue;
		if (!dfs(y, x)) return false;
		if (f[y] > 0)
		{
			if (out == 0)
				out = f[y];
			else
				return false;
		}
		in = max(g[y], in);
	}
	if (st[x] != 0 && out != 0)
		return false;
	if (out != 0)
	{
		if (in >= out - 1)
			f[x] = 0;
		else
			f[x] = out - 1;
		g[x] = 0;
	}
	else if (st[x] != 0)
	{
		if (in >= len[x])
			f[x] = 0;
		else
			f[x] = len[x];
		g[x] = 0;
	}
	else
	{
		f[x] = 0;
		g[x] = in + 1;
	}
	return true;
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		e[i].clear();
		st[i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x); 
	}
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		int x;
		scanf("%d", &x);
		st[x] = i;
	}
	int l = 0, r = n;
	while (l < r)
	{
		int mid = l + r >> 1;
		for (int i = 1; i <= n; i++)
			len[i] = f[i] = g[i] = 0;
		for (int i = 1; i <= n; i++)
			if (st[i] != 0)
				len[i] = (mid + 1 - st[i] + k) / k;
		if (!dfs(1, 0) || f[1] > 0) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

