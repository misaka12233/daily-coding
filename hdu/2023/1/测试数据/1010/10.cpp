#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int T;
int n, m;
int a[maxn];
struct node{
	int l, r;
	int cnt;
	ll mn, mnid, sum;
	ll p0, p1;
};
node tr[2][maxn << 2];
void pushup(int id, int x)
{
	int lc = x << 1, rc = x << 1 | 1;
	tr[id][x].cnt = tr[id][lc].cnt + tr[id][rc].cnt;
	tr[id][x].sum = tr[id][lc].sum + tr[id][rc].sum;
	if (id == 0)
	{
		if (tr[id][lc].mn <= tr[id][rc].mn)
		{
			tr[id][x].mn = tr[id][lc].mn;
			tr[id][x].mnid = tr[id][lc].mnid;
		}
		else
		{
			tr[id][x].mn = tr[id][rc].mn;
			tr[id][x].mnid = tr[id][rc].mnid;
		}
	}
}
void pushdown(int id, int x)
{
	if (tr[id][x].p0 == 0 && tr[id][x].p1 == 1) return;
	
	int lc = x << 1, rc = x << 1 | 1;
	if (id == 0)
	{
		if (tr[id][lc].cnt != 0)
		{
			tr[id][lc].sum = tr[id][x].p0 * tr[id][lc].cnt + tr[id][lc].sum;
			tr[id][lc].mn = tr[id][x].p0 + tr[id][lc].mn;
			tr[id][lc].p0 = tr[id][x].p0 + tr[id][lc].p0;
		}
		if (tr[id][rc].cnt != 0)
		{
			tr[id][rc].sum = tr[id][x].p0 * tr[id][rc].cnt + tr[id][rc].sum;
			tr[id][rc].mn = tr[id][x].p0 + tr[id][rc].mn;
			tr[id][rc].p0 = tr[id][x].p0 + tr[id][rc].p0;
		}
	}
	else
	{
		if (tr[id][lc].cnt != 0)
		{
			tr[id][lc].sum = tr[id][x].p0 * tr[id][lc].cnt + tr[id][x].p1 * tr[id][lc].sum;
			tr[id][lc].p0 = tr[id][x].p0 + tr[id][lc].p0 * tr[id][x].p1;
			tr[id][lc].p1 = tr[id][lc].p1 * tr[id][x].p1;
		}
		if (tr[id][rc].cnt != 0)
		{
			tr[id][rc].sum = tr[id][x].p0 * tr[id][rc].cnt + tr[id][x].p1 * tr[id][rc].sum;
			tr[id][rc].p0 = tr[id][x].p0 + tr[id][rc].p0 * tr[id][x].p1;
			tr[id][rc].p1 = tr[id][rc].p1 * tr[id][x].p1;
		}
	}
	
	tr[id][x].p0 = 0;
	tr[id][x].p1 = 1;
}
void build(int x, int l, int r)
{
	tr[0][x].l = tr[1][x].l = l;
	tr[0][x].r = tr[1][x].r = r;
	tr[0][x].p0 = tr[1][x].p0 = 0;
	tr[0][x].p1 = tr[1][x].p1 = 1;
	if (l == r)
	{
		tr[0][x].cnt = 1;
		tr[0][x].mn = tr[0][x].sum = a[l];
		tr[0][x].mnid = l;
		
		tr[1][x].cnt = 0;
		tr[1][x].mn = inf;
		tr[1][x].sum = 0;
		tr[1][x].mnid = l;
		return;
	}
	int lc = x << 1, rc = x << 1 | 1, mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(0, x);
	pushup(1, x);
}
void update(int id, int x, int l, int r, ll p0, ll p1)
{
	if (tr[id][x].cnt == 0)
		return;
	if (l <= tr[id][x].l && tr[id][x].r <= r)
	{
		tr[id][x].sum = p0 * tr[id][x].cnt + p1 * tr[id][x].sum;
		tr[id][x].mn = p0 + p1 * tr[id][x].mn;
		tr[id][x].p0 = p0 + tr[id][x].p0 * p1;
		tr[id][x].p1 = tr[id][x].p1 * p1;
		return;
	}
	pushdown(id, x);
	int lc = x << 1, rc = x << 1 | 1, mid = tr[id][x].l + tr[id][x].r >> 1;
	if (l <= mid) update(id, lc, l, r, p0, p1);
	if (r > mid) update(id, rc, l, r, p0, p1);
	pushup(id, x);
}
ll getsum(int id, int x, int l, int r)
{
	if (tr[id][x].cnt == 0)
		return 0;
	if (l <= tr[id][x].l && tr[id][x].r <= r)
		return tr[id][x].sum;
	pushdown(id, x);
	int lc = x << 1, rc = x << 1 | 1, mid = tr[id][x].l + tr[id][x].r >> 1;
	ll res = 0;
	if (l <= mid) res += getsum(id, lc, l, r);
	if (r > mid) res += getsum(id, rc, l, r);
	pushup(id, x);
	return res;
}
pii getmin(int id, int x, int l, int r)
{
	if (tr[id][x].cnt == 0)
		return pii(inf, 0);
	if (l <= tr[id][x].l && tr[id][x].r <= r)
		return pii(tr[id][x].mn, tr[id][x].mnid);
	pushdown(id, x);
	int lc = x << 1, rc = x << 1 | 1, mid = tr[id][x].l + tr[id][x].r >> 1;
	pii res = pii(inf, 0);
	if (l <= mid) res = min(res, getmin(id, lc, l, r));
	if (r > mid) res = min(res, getmin(id, rc, l, r));
	pushup(id, x);
	return res;
}
void remake_node(int id, int x, int pos, int val, int cnt)
{
	if (pos == tr[id][x].l && tr[id][x].r == pos)
	{
		tr[id][x].cnt = cnt;
		tr[id][x].mn = inf;
		tr[id][x].sum = val;
		return; 
	}
	pushdown(id, x);
	int lc = x << 1, rc = x << 1 | 1, mid = tr[id][x].l + tr[id][x].r >> 1;
	if (pos <= mid) remake_node(id, lc, pos, val, cnt);
	else remake_node(id, rc, pos, val, cnt);
	pushup(id, x);
	return;
}

template <typename type>
void read(type &a) 
{
    int t, f = 0;
    while (!isdigit(t = getchar())) 
        f |= t == '-';
    a = t - '0';
    while ( isdigit(t = getchar())) 
    {
        a *= 10;
        a += t - '0';
    }
    a = f ? -a : a;
}
void sol()
{
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++)
	{
		int op, l, r, x;
		read(op), read(l), read(r);
		if (op == 1)
		{
			read(x);
			pii mn = getmin(0, 1, l, r);
			while (mn.first <= x)
			{
				remake_node(0, 1, mn.second, 0, 0);
				remake_node(1, 1, mn.second, mn.first, 1);
				mn = getmin(0, 1, l, r);
			}
			update(0, 1, l, r, -x, 1);
			update(1, 1, l, r, x, -1);
		}
		else
			printf("%lld\n", getsum(0, 1, l, r) + getsum(1, 1, l, r));
	}
}
int main()
{
	/*
	int st_tim = clock();
	freopen("1010.in", "r", stdin);
	freopen("myans.out", "w", stdout);
	*/
	read(T);
	while (T--) sol();
	//printf("%d\n", clock() - st_tim);
	return 0;
}

