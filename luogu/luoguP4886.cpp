#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
struct node{
	node (int v, int w) : v(v), w(w) {}
	int v;
	int w;
};
bool vis[maxn];
vector<node> qry; 
vector<node> e[maxn];
int ans, res, rt, sum;
int dis[maxn], subtr[maxn];
int siz[maxn], mxSiz[maxn];
void getres(int u, int f, int tr)
{
	subtr[u] = tr;
	for (auto now : e[u])
	{
		int v = now.v, w = now.w;
		if (v == f) continue;
		dis[v] = dis[u] + w;
		if (u == rt)
			getres(v, u, v);
		else
			getres(v, u, tr);
	}
}
void getroot(int u, int f)
{
	siz[u] = 1;
	mxSiz[u] = 0;
	for (auto now : e[u])
	{
		int v = now.v, k = now.w;
		if (v == f || vis[v]) continue;
		getroot(v, u);
		siz[u] += siz[v];
		mxSiz[u] = max(mxSiz[u], siz[v]);
	}
	mxSiz[u] = max(mxSiz[u], sum - siz[u]);
	if (mxSiz[u] < mxSiz[rt]) rt = u;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		e[u].push_back(node(v, w));
		e[v].push_back(node(u, w));
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		qry.push_back(node(u, v));
	}
	mxSiz[0] = ans = inf;
	rt = 0;
	sum = n;
	getroot(1, 0);
	while (1)
	{
		dis[rt] = 0;
		getres(rt, rt, rt);
		int pre = -1;
		res = 0;
		for (auto now : qry)
		{
			int u = now.v, v = now.w;
			res = max(res, dis[u] + dis[v]);
		}
		for (auto now : qry)
		{
			int u = now.v, v = now.w;
			if (dis[u] + dis[v] == res)
			{
				if (subtr[u] != subtr[v]) goto STOP;
				if (pre == -1) pre = subtr[u];
				else if (pre != subtr[u]) goto STOP;
			}
		}
		if (vis[pre]) goto STOP;
		ans = min(ans, res);
		vis[rt] = true;
		rt = 0;
		sum = siz[pre];
		getroot(pre, 0);
		if (vis[rt]) goto STOP;
	}
	STOP: ans = min(ans, res);
	printf("%d\n", ans);
	return 0;
}

