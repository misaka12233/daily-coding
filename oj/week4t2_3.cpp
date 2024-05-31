#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n;
ll c;
struct node{
	ll x, y;
	int num;
};
node v[maxn];
set<pli> nowy;
int fa[maxn], siz[maxn];
int getfa(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
void Union(int x, int y)
{
	int fx = getfa(x), fy = getfa(y);
	if (fx != fy)
	{
		fa[fx] = fy;
		siz[fy] += siz[fx];
	}
}
bool cmp(node a, node b)
{
	return a.x < b.x;
}
int main()
{
	scanf("%d%lld", &n, &c);
	for (int i = 1; i <= n; i++)
	{
		ll a, b;
		scanf("%lld%lld", &a, &b);
		v[i].x = a - b;
		v[i].y = a + b;
		v[i].num = i;
		fa[i] = i;
		siz[i] = 1;
	}
	sort(v + 1, v + n + 1, cmp);
	int nowx = 1;
	nowy.insert({v[1].y, v[1].num});
	for (int i = 2; i <= n; i++)
	{
		while (v[i].x - v[nowx].x > c)
		{
			nowy.erase({v[nowx].y, v[nowx].num});
			nowx++;
		}
		auto it = nowy.lower_bound({v[i].y - c, 0});
		if (it != nowy.end() && (*it).first <= v[i].y + c)
			Union((*it).second, v[i].num);
		it = nowy.lower_bound({v[i].y, 0});
		if (it != nowy.end() && (*it).first <= v[i].y + c)
			Union((*it).second, v[i].num);
		nowy.insert({v[i].y, v[i].num});
	}
	int cnt, mx;
	cnt = mx = 0;
	for (int i = 1; i <= n; i++)
	{
		if (fa[i] == i)
		{
			cnt++;
			mx = max(mx, siz[i]);
		}
	}
	printf("%d\n%d\n", cnt, mx);
	return 0;
}

