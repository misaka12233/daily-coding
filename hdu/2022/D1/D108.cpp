#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
int T;
int n, m, s;
ll k;
struct node{
	int y;
	ll w;
	int t;
};
vector<node> edge[maxn];
ll dis[maxn][2];
bool vis[maxn][2];
set<int> togo;
struct vertex{
	int x, t;
	ll d;
	vertex(int x, int t, ll d)
	{
		this->x = x;
		this->t = t;
		this->d = d;
	}
	bool operator < (const vertex &tmp) const
	{
		return d > tmp.d;
	}
};
priority_queue<vertex> q;
void dij()
{
	dis[s][0] = 0;
	q.push(vertex(s, 0, 0));
	while(!q.empty())
	{
		if (togo.empty()) break;
		int x = q.top().x, t = q.top().t;
		q.pop();
		if (vis[x][t]) continue;
		vis[x][t] = true;
		if (togo.find(x) != togo.end()) togo.erase(x);
		ll ext = 0;
		if (t)
		{
			ext = -k;
			set<int> tmp;
			tmp.insert(togo.begin(), togo.end());
			for (auto now : edge[x])
				tmp.erase(now.y);
			for (auto y : tmp)
			{
				dis[y][0] = dis[x][t];
				q.push(vertex(y, 0, dis[y][0]));
				togo.erase(y);
			}
		}
		for (auto now : edge[x])
		{
			if (dis[now.y][now.t] > dis[x][t] + now.w + ext)
			{
				dis[now.y][now.t] = dis[x][t] + now.w + ext;
				q.push(vertex(now.y, now.t, dis[now.y][now.t]));
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d%lld", &n, &m, &s, &k);
		togo.clear();
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++)
		{
			edge[i].clear();
			dis[i][0] = dis[i][1] = 1ll * m * inf;
			vis[i][0] = vis[i][1] = false;
			togo.insert(i);
		}
		for (int i = 1; i <= m; i++)
		{
			int x, y;
			node tmp;
			scanf("%d%d%lld%d", &x, &y, &tmp.w, &tmp.t);
			tmp.y = y;
			edge[x].push_back(tmp);
		}
		dij();
		for (int i = 1; i <= n; i++)
		{
			ll ans = min(dis[i][0], dis[i][1]);
			if (ans == 1ll * m * inf) printf("-1 ");
			else printf("%lld ", ans);
		}
		puts("");
	}
	return 0;
}

