#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n, q; 
vector<int> edge[maxn];
int fa[maxn];

int siz[maxn], son[maxn];
int dfn[maxn], top[maxn], tim;
void getsiz(int x)
{
	siz[x] = 1;
	for (auto y : edge[x])
	{
		getsiz(y);
		siz[x] += siz[y];
		if (siz[y] > siz[son[x]]) son[x] = y;
	}
}
void getdfn(int x, int tp)
{
	dfn[x] = ++tim;
	top[x] = tp;
	if (son[x]) getdfn(son[x], tp);
	for (auto y : edge[x])
	{
		if (y == son[x]) continue;
		getdfn(y, y);
	}
}

struct node{
	int l, r;
	int sum;
	int cnt[2];
	int laz[2];
};
node tr[maxn << 2];
void pushup(int x)
{
	int lc = x << 1, rc = x << 1 | 1;
	for (int i = 0; i < 2; i++)
		tr[x].cnt[i] = tr[lc].cnt[i] + tr[rc].cnt[i];
	tr[x].sum = tr[lc].sum + tr[rc].sum;
}
void pushdown(int x)
{
	int lc = x << 1, rc = x << 1 | 1;
	for (int i = 0; i < 2; i++)
	{
		if (tr[x].laz[i] == 1)
		{
			tr[lc].cnt[i] = tr[lc].r - tr[lc].l + 1;
			tr[rc].cnt[i] = tr[rc].r - tr[rc].l + 1;
			tr[lc].laz[i] = tr[rc].laz[i] = 1;
			tr[x].laz[i] = -1;
			tr[lc].sum = tr[lc].cnt[i ^ 1];
			tr[rc].sum = tr[rc].cnt[i ^ 1];
		}
		else if (tr[x].laz[i] == 0)
		{
			tr[lc].cnt[i] = 0;
			tr[rc].cnt[i] = 0;
			tr[lc].laz[i] = tr[rc].laz[i] = 0;
			tr[x].laz[i] = -1;
			tr[lc].sum = 0;
			tr[rc].sum = 0;
		}
	}
}
void build(int x, int l, int r)
{
	tr[x].l = l, tr[x].r = r;
	tr[x].cnt[0] = tr[x].cnt[1] = tr[x].sum = 0;
	tr[x].laz[0] = tr[x].laz[1] = -1;
	if (tr[x].l == tr[x].r) return;
	int mid = tr[x].l + tr[x].r >> 1, lc = x << 1, rc = x << 1 | 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
}
void update(int x, int l, int r, int op, int v)
{
	if (l <= tr[x].l && tr[x].r <= r)
	{
		if (v == 1)
		{
			tr[x].cnt[op] = tr[x].r - tr[x].l + 1;
			tr[x].laz[op] = 1;
			tr[x].sum = tr[x].cnt[op ^ 1];
		}
		else
		{
			tr[x].cnt[op] = 0;
			tr[x].laz[op] = 0;
			tr[x].sum = 0;
		}
		return;
	}
	pushdown(x);
	int mid = tr[x].l + tr[x].r >> 1, lc = x << 1, rc = x << 1 | 1;
	if (l <= mid) update(lc, l, r, op, v);
	if (r > mid) update(rc, l, r, op, v);
	pushup(x);
}
int query(int x, int l, int r)
{
	if (l <= tr[x].l && tr[x].r <= r)
		return tr[x].sum;
	pushdown(x);
	int mid = tr[x].l + tr[x].r >> 1, lc = x << 1, rc = x << 1 | 1, res = 0;
	if (l <= mid) res += query(lc, l, r);
	if (r > mid) res += query(rc, l, r);
	pushup(x);
	return res;
}

int range[maxn];
bool cmp(int x, int y)
{
	return dfn[x] < dfn[y];
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &q);
		for (int i = 1; i <= n; i++)
		{
			edge[i].clear();
			son[i] = 0;
		}
		tim = 0;
		build(1, 1, n);
		for (int i = 2; i <= n; i++)
		{
			scanf("%d", fa + i);
			edge[fa[i]].push_back(i);
		}
		getsiz(1);
		getdfn(1, 1);
		while (q--)
		{
			update(1, 1, n, 0, 0);
			update(1, 1, n, 1, 0);
			int k[3], x;
			for (int i = 0; i < 3; i++)
				scanf("%d", k + i);
			for (int i = 0; i < 2; i++)
			{
				while (k[i]--)
				{
					scanf("%d", &x);
					while (x != 0)
					{
						update(1, dfn[top[x]], dfn[x], i, 1);
						x = fa[top[x]];
					}
				}
			}
			for (int i = 1; i <= k[2]; i++)
				scanf("%d", range + i);
			sort(range + 1, range + k[2] + 1, cmp);
			int lst = 0, m = 0;
			for (int i = 1; i <= k[2]; i++)
			{
				if (dfn[range[i]] > lst)
				{
					lst = dfn[range[i]] + siz[range[i]] - 1;
					range[++m] = range[i];
				}
			}
			int ans = 0;
			for (int i = 1; i <= m; i++)
				ans += query(1, dfn[range[i]], dfn[range[i]] + siz[range[i]] - 1);
			printf("%d\n", ans);
		}
	}
	return 0;
}

