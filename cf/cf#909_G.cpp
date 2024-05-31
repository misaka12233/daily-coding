#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int K = 17;
int n, q, cnt;
int p[maxn];
int in[maxn], out[maxn];
vector<int> e[maxn];
struct node{
	node(int id, int l, int r, int op): id(id), l(l), r(r), op(op) {}
	node() {}
	int id;
	int l, r;
	int op;
};
vector<node> qry[maxn];
int tr[maxn];
int res[maxn];
int lowbit(int x)
{
	return x & -x;
}
void update(int x)
{
	for (int i = x; i <= n; i += lowbit(i))
		tr[i]++;
}
int query(int x)
{
	int r = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		r += tr[i];
	return r;
}
void dfs(int x, int pa)
{
	in[x] = ++cnt;
	for (auto y : e[x])
	{
		if (y == pa) continue;
		dfs(y, x);
	}
	out[x] = cnt;
}
void sol()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		e[i].clear();
		tr[i] = 0;
	}
	for (int i = 1; i <= q; i++)
	{
		qry[i].clear();
		res[i] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	cnt = 0;
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		scanf("%d", p + i);
	for (int i = 1; i <= q; i++)
	{
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		qry[l - 1].push_back(node(i, in[x], out[x], -1));
		qry[r].push_back(node(i, in[x], out[x], 1));
	}
	for (int i = 1; i <= n; i++)
	{
		update(in[p[i]]);
		for (auto u : qry[i])
		{
			int val = query(u.r) - query(u.l - 1);
			res[u.id] += val * u.op;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		if (res[i] > 0)
			puts("Yes");
		else
			puts("No"); 
	}
	printf("\n"); 
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

