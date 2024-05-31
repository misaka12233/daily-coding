#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
typedef long long ll;
int n, q;
ll mod;
struct node{
	int l, r;
	ll sum;
	ll laz_mul, laz_add;
}; 
node tr[maxn << 2];
ll a[maxn];
void pushup(int x)
{
	int lc = x << 1, rc = x << 1 | 1;
	tr[x].sum = (tr[lc].sum + tr[rc].sum) % mod;
}
void pushdown(int x)
{
	int lc = x << 1, rc = x << 1 | 1;
	if (tr[x].laz_mul != 1 || tr[x].laz_add != 0)
	{
		tr[lc].sum = (tr[lc].sum * tr[x].laz_mul % mod + (tr[lc].r - tr[lc].l + 1) * tr[x].laz_add) % mod;
		tr[lc].laz_mul = tr[lc].laz_mul * tr[x].laz_mul % mod;
		tr[lc].laz_add = (tr[lc].laz_add * tr[x].laz_mul % mod + tr[x].laz_add) % mod;
		tr[rc].sum = (tr[rc].sum * tr[x].laz_mul % mod + (tr[rc].r - tr[rc].l + 1) * tr[x].laz_add) % mod;
		tr[rc].laz_mul = tr[rc].laz_mul * tr[x].laz_mul % mod;
		tr[rc].laz_add = (tr[rc].laz_add * tr[x].laz_mul % mod + tr[x].laz_add) % mod;
		tr[x].laz_mul = 1;
		tr[x].laz_add = 0;
	}
}
void build(int x, int l, int r)
{
	tr[x].l = l;
	tr[x].r = r;
	tr[x].sum = 0;
	tr[x].laz_mul = 1;
	tr[x].laz_add = 0;
	if (l == r)
	{
		tr[x].sum = a[l];
		return;
	}
	int mid = l + r >> 1;
	int lc = x << 1, rc = x << 1 | 1;
	build(lc, l, mid);
	build(rc, mid + 1, r);
	pushup(x);
}
void update(int x, int l, int r, ll m, ll a)
{
	if (l <= tr[x].l && tr[x].r <= r)
	{
		tr[x].sum = (tr[x].sum * m % mod + (tr[x].r - tr[x].l + 1) * a % mod) % mod;
		tr[x].laz_mul = tr[x].laz_mul * m % mod;
		tr[x].laz_add = (tr[x].laz_add * m % mod + a) % mod;
		return;
	}
	int mid = tr[x].l + tr[x].r >> 1;
	int lc = x << 1, rc = x << 1 | 1;
	pushdown(x);
	if (l <= mid)
		update(lc, l, r, m, a);
	if (r > mid)
		update(rc, l, r, m, a);
	pushup(x);
}
ll query(int x, int l, int r)
{
	if (l <= tr[x].l && tr[x].r <= r)
		return tr[x].sum;
	int mid = tr[x].l + tr[x].r >> 1;
	int lc = x << 1, rc = x << 1 | 1;
	ll res = 0;
	pushdown(x);
	if (l <= mid)
		res = (res + query(lc, l, r)) % mod;
	if (r > mid)
		res = (res + query(rc, l, r)) % mod;
	pushup(x);
	return res;
}
int main()
{
	scanf("%d%d%lld", &n, &q, &mod);
	for (int i = 1; i <= n; i++)
		scanf("%d", a + i);
	build(1, 1, n);
	for (int i = 1; i <= q; i++)
	{
		int op, l, r;
		ll k;
		scanf("%d%d%d", &op, &l, &r);
		if (op == 1)
		{
			scanf("%lld", &k);
			update(1, l, r, k, 0);
		}
		else if (op == 2)
		{
			scanf("%lld", &k);
			update(1, l, r, 1, k);
		}
		else if (op == 3)
			printf("%lld\n", query(1, l, r));
	}
	return 0;
}

