#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 50000 + 10;
int n;
struct node{
	int t;
	int p;
};
node a[maxn];
vector<pii> e[maxn];
int fa[maxn];
int getfa(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = getfa(fa[x]);
}
bool cmp(node x, node y)
{
	return x.p < y.p;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i].p);
			a[i].t = i;
			fa[i] = i;
			e[i].clear();
		}
		int sqrn = sqrt(n);
		for (int l = 1; l <= sqrn; l++)
		{
			for (int i = 1; i + l <= n; i++)
			{
				int now = abs(a[i].t - a[i + l].t) * abs(a[i].p - a[i + l].p);
				if (now < n) e[now].push_back({a[i].t, a[i + l].t});
			}
		}
		sort(a + 1, a + n + 1, cmp);
		for (int l = 1; l <= sqrn; l++)
		{
			for (int i = 1; i + l <= n; i++)
			{
				int now = abs(a[i].t - a[i + l].t) * abs(a[i].p - a[i + l].p);
				if (now < n) e[now].push_back({a[i].t, a[i + l].t});
			}
		}
		ll ans = 0;
		for (int i = 1; i < n; i++)
		{
			for (auto j : e[i])
			{
				int u = j.first, v = j.second;
				int fu = getfa(u), fv = getfa(v);
				if (fu != fv)
				{
					ans = ans + i;
					fa[fu] = fv;
					//printf("%d %d %d\n", u, v, i);
				}
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}

