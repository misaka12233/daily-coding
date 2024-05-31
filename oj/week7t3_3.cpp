#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 3000 + 10;
typedef long long ll;
int n, mx;
ll dis[maxn], c, ans, ori_ans;
ll diam_half[2][2];
int pre[maxn];
struct node{
	int v;
	ll w;
	node() {}
	node(int v, ll w): v(v), w(w) {}
};
vector<node> e[maxn];
int delu, delv;
void get_diam(int u, int fa)
{
	pre[u] = fa;
	if (dis[u] > dis[mx]) mx = u;
	for (auto now : e[u])
	{
		int v = now.v;
		if (v == fa || (delu == max(u, v) && delv == min(u, v))) continue;
		dis[v] = dis[u] + now.w;
		get_diam(v, u);
	}
}
void get_mid(int u, int to)
{
	mx = u;
	dis[mx] = 0; get_diam(mx, 0);
	dis[mx] = 0; get_diam(mx, 0);
	int v = mx, now = mx;
	while (v != 0)
	{
		if (max(dis[v], dis[mx] - dis[v]) < max(dis[now], dis[mx] - dis[now]))
			now = v;
		v = pre[v];
	}
	diam_half[to][0] = dis[now];
	diam_half[to][1] = dis[mx] - dis[now];
}
void dfs(int u, int fa)
{
	for (auto now : e[u])
	{
		int v = now.v;
		if (v == fa) continue;
		delu = max(u, v);
		delv = min(u, v);
		get_mid(u, 0);
		get_mid(v, 1);
		ll tmp = max(diam_half[0][0], diam_half[0][1]) + max(diam_half[1][0], diam_half[1][1]) + c;
		   tmp = max(tmp, diam_half[0][0] + diam_half[0][1]);
		   tmp = max(tmp, diam_half[1][0] + diam_half[1][1]);
		ans = min(ans, tmp);
		dfs(v, u);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int u, v;
		ll w;
		scanf("%d%d%lld", &u, &v, &w);
		e[u].push_back(node(v, w));
		e[v].push_back(node(u, w));
	}
	scanf("%lld", &c);
	mx = 1;
	dis[mx] = 0; get_diam(mx, 0);
	dis[mx] = 0; get_diam(mx, 0);
	ori_ans = dis[mx];
	ans = 1ll * maxn * inf;
	dfs(1, 0);
	if (ori_ans <= ans) puts("no");
	else
	{
		puts("yes");
		printf("%lld\n", ans);
	}
	return 0;
}
/*
7
1 2 5
2 3 1
2 4 2
1 5 3
5 6 6
5 7 4
3
*/
