#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const ll inf = 0xfffffffffffffff;
const int maxn = 400000 + 10;
int T;
int n, m, k;
int cnt;
map<pii, int> num;
priority_queue<int> ladder[maxn];//´æ´¢ÌÝ×Ó 
ll dis_floor[maxn];

int hd[maxn], tot;
int to[maxn << 5], nxt[maxn << 5];
ll val[maxn << 5], dis[maxn];
bool vis[maxn];//½¨Í¼
void add(int x1, int y1, int x2, int y2, ll w)
{
	int x = num[pii(x1, y1)], y = num[pii(x2, y2)];
	tot++;
	to[tot] = y;
	nxt[tot] = hd[x];
	val[tot] = w;
	hd[x] = tot;
}
queue<int> q;
void spfa()
{
	q.push(1);
	vis[1] = true;
	dis[1] = 0;
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		vis[x] = false;
		for (int i = hd[x]; i ; i = nxt[i])
		{
			int y = to[i];
			if (dis[y] > dis[x] + val[i])
			{
				dis[y] = dis[x] + val[i];
				if (!vis[y])
				{
					q.push(y);
					vis[y] = true;
				}
			}
		}
	}
}
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		tot = cnt = 0;
		num.erase(num.begin(), num.end());
		for (int i = 1; i <= 2 * k + 2; i++)
		hd[i] = 0, dis[i] = inf;
		for (int i = 1; i <= n; i++)
			scanf("%lld", dis_floor + i);
		num[pii(1, 1)] = ++cnt;
		num[pii(n, m)] = ++cnt;
		bool have_1 = false, have_n = false;
		for (int i = 1; i <= k; i++)
		{
			int a, b, c, d, h;
			scanf("%d%d%d%d%d", &a, &b, &c, &d, &h);
			num.insert(pair<pii, int>(pii(a, b), ++cnt));
			num.insert(pair<pii, int>(pii(c, d), ++cnt));
			add(a, b, c, d, -h);
			ladder[a].push(b);
			ladder[c].push(d);
			if (a == 1 && b == 1) have_1 = true;
			if (c == n && d == m) have_n = true;
		}
		if (!have_1) ladder[1].push(1);
		if (!have_n) ladder[n].push(m);
		for (int i = 1; i <= n; i++)
		{
			int lst = 0;
			while(!ladder[i].empty())
			{
				int x = ladder[i].top();
				ladder[i].pop();
				if (lst)
				{
					add(i, lst, i, x, dis_floor[i] * (lst - x));
					add(i, x, i, lst, dis_floor[i] * (lst - x));
				}
				lst = x;
			}
		}
		spfa();
		if (dis[2] == inf)
			puts("NO ESCAPE");
		else
			printf("%lld\n", dis[2]);
	}
	return 0;
}

