#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
typedef long long ll;
int n, q;
ll a[maxn];
struct node{
	node(int ver, ll val): ver(ver), val(val) {}
	int ver;
	ll val;
};
vector<node> d[maxn];
set<int> difpos;
int getnum(int pos, int ver)
{
	int l = 0, r = d[pos].size() - 1;
	while (l < r)
	{
		int mid = l + r >> 1;
		if (d[pos][mid + 1].ver <= ver) l = mid + 1;
		else r = mid;
	}
	return l;
}
void update(int ver, int pos, ll val, int base)
{
	if (pos > n) return;
	int st = getnum(pos, base), ed = d[pos].size() - 1;
	ll newv = d[pos][ed].val + val;
	d[pos].push_back(node(ver, newv));
	if (newv != d[pos][st].val)
		difpos.insert(pos);
	else
		difpos.erase(pos);
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		d[i].clear();
		d[i].push_back(node(0, 0));
	}
	difpos.clear();
	for (int i = 1; i <= n; i++)
		scanf("%lld", a + i);
	scanf("%d", &q);
	int mn = 0;
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		ll x;
		scanf("%d%d%lld", &l, &r, &x);
		update(i, l, x, mn);
		update(i, r + 1, -x, mn);
		if (!difpos.empty())
		{
			int p = *difpos.begin();
			if (d[p][getnum(p, i)].val < d[p][getnum(p, mn)].val)
			{
				difpos.clear();
				mn = i;
			}
		}
	}
	ll s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += d[i][getnum(i, mn)].val;
		printf("%lld ", a[i] + s);
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

