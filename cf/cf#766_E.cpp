#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const ll inf = 0xffffffffffff;
const int maxn = 100000 + 10;
struct node{
	node(int r, int c, ll h)
	{
		p.first = r;
		p.second = c;
		this->h = h;
	}
	node() {}
	pii p;
	ll h;
};
map<pii, vector<node> > e;
map<pii, ll> dis;
pii v[maxn << 1];
int n, m, k, cnt;
ll x[maxn];
void update(pii x, ll val)
{
	if (dis.find(x) == dis.end())
		dis[x] = val;
	else
		dis[x] = min(dis[x], val);
}
void sol()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf("%lld", x + i);
	cnt = 0;
	e.clear();
	dis.clear();
	for (int i = 1; i <= k; i++)
	{
		int a, b, c, d;
		ll h;
		scanf("%d%d%d%d%lld", &a, &b, &c, &d, &h);
		e[pii(c, d)].push_back(node(a, b, h));
		v[++cnt] = pii(a, b);
		v[++cnt] = pii(c, d);
	}
	v[++cnt] = pii(1, 1);
	v[++cnt] = pii(n, m);
	sort(v + 1, v + cnt + 1);
	int tmp = 0;
	for (int i = 1; i <= cnt; i++)
	{
		if (i + 1 <= cnt && v[i] == v[i + 1]) 
			continue;
		v[++tmp] = v[i];
	}
	cnt = tmp;
	dis[pii(1, 1)] = 0;
	int l = 1, r;
	while (l <= cnt)
	{
		r = l;
		while (r + 1 <= cnt && v[r].first == v[r + 1].first)
			r++;
		for (int i = l; i <= r; i++)
			for (auto u : e[v[i]])
				if (dis.find(u.p) != dis.end())
					update(v[i], dis[u.p] - u.h);
		int h = v[l].first;
		for (int i = l + 1; i <= r; i++)
			if (dis.find(v[i - 1]) != dis.end())
				update(v[i], dis[v[i - 1]] + x[h] * (v[i].second - v[i - 1].second));
		for (int i = r - 1; i >= l; i--)
			if (dis.find(v[i + 1]) != dis.end())
				update(v[i], dis[v[i + 1]] + x[h] * (v[i + 1].second - v[i].second));
		l = r + 1;
	}
	if (dis.find(pii(n, m)) == dis.end())
		puts("NO ESCAPE"); 
	else
		printf("%lld\n", dis[pii(n, m)]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

