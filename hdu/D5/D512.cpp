#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, m;
struct people{
	ll a, s;
};
people p[maxn];
ll ed[maxn];
priority_queue<pli> q;
bool cmp(people x, people y)
{
	return x.a < y.a;
}

struct node{
	int l,r;
	int mn;
	int num;
};
node tr[maxn<<2];
void build(int x,int l,int r)
{
	tr[x].l=l;
	tr[x].r=r;
	tr[x].mn=0;
	tr[x].num=l;
	if(l==r)
		return;
	int mid=l+r>>1,lc=x<<1,rc=x<<1|1;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
void add(int x,int p,int v)
{
	if(tr[x].l == tr[x].r)
	{
		tr[x].mn += v;
		return;
	}
	int mid=tr[x].l+tr[x].r>>1,lc=x<<1,rc=x<<1|1;
	if(p<=mid) add(lc,p,v);
	else add(rc,p,v);
	if (tr[lc].mn <= tr[rc].mn)
	{
		tr[x].mn = tr[lc].mn;
		tr[x].num = tr[lc].num;
	}
	else
	{
		tr[x].mn = tr[rc].mn;
		tr[x].num = tr[rc].num;
	}
}

void sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld%lld", &p[i].a, &p[i].s);
	sort(p + 1, p + n + 1, cmp);
	for (int i = 1; i <= m; i++)
		ed[i] = 0;
	build(1, 1, m);
	while (!q.empty()) q.pop();
	ll ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int x;
		while (!q.empty())
		{
			ll tim = -q.top().first;
			x = q.top().second;
			if (tim <= p[i].a)
			{
				q.pop();
				add(1, x, -1);
			}
			else break;
		}
		x = tr[1].num;
		ed[x] = max(ed[x], p[i].a) + p[i].s;
		add(1, x, 1);
		q.push({-ed[x], x});
		ans = max(ans, ed[x]);
	}
	printf("%lld\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		sol();
	}
	return 0;
}

