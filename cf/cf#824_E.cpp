#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
typedef long long ll;
int n;
vector<ll> ans, res;
struct node{
	node() {val = id = t = 0;}
	node(ll val, int id, int t): val(val), id(id), t(t) {}
	ll val;
	int id;
	int t;
	bool operator < (node b) const
	{
		if (val == b.val && t == b.t) return id < b.id;
		if (val == b.val) return t < b.t;
		return val < b.val;
	}
};
ll d[2][maxn];
multiset<node> s[2];
priority_queue<node> q;
int mat[2][maxn];
void sol()
{
	scanf("%d", &n);
	ans.clear();
	res.clear();
	for (int i = 0; i < 2; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &d[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ll a = d[0][i] + d[1][j];
			ll b = abs(d[0][i] - d[1][j]);
			res.push_back(a);
			if (a != b)
				res.push_back(b);
		}
	}
	sort(res.begin(), res.end());
	int now = -1, m = res.size();
	ll len = -1;
	while (now < m)
	{
		now++;
		int l = now, r;
		while (now + 1 < m && res[now] == res[now + 1])
			now++;
		r = now;
		if (r - l + 1 < n)
			continue;
		ll nowlen = res[now];
		while (!q.empty()) q.pop();
		for (int i = 0; i < 2; i++)
		{
			s[i].clear();
			for (int j = 1; j <= n; j++)
			{
				mat[i][j] = 0;
				node tmp(d[i][j], j, i);
				q.push(tmp);
				s[i].insert(tmp);
			}
		}
		bool succ = true;
		while (!q.empty())
		{
			node x = q.top();
			int u = x.id, t = x.t;
			ll h = x.val;
			q.pop();
			if (s[t].find(x) == s[t].end()) continue;
			ll need = abs(h - nowlen);
			auto p = lower_bound(s[t ^ 1].begin(), s[t ^ 1].end(), node(need, 0, 0));
			if (p == s[t ^ 1].end() || (*p).val != need)
			{
				succ = false;
				break;
			}
			mat[t][u] = (*p).id;
			mat[t ^ 1][(*p).id] = u;
			s[t].erase(x);
			s[t ^ 1].erase(p);
		}
		if (succ)
		{
			len = nowlen;
			break;
		}
	}
	if (len == -1)
	{
		puts("NO");
		return;
	}
	puts("YES");
	for (int i = 1; i <= n; i++)
	{
		if (d[0][i] + d[1][mat[0][i]] == len)
			ans.push_back(d[0][i]);
		else
		{
			if (d[0][i] > d[1][mat[0][i]])
				ans.push_back(d[0][i]);
			else
				ans.push_back(len - d[1][mat[0][i]]);
		}
	}
	sort(ans.begin(), ans.end());
	ll mn = min(ans[0], 0ll);
	for (auto x : ans)
		printf("%lld ", x - mn);
	printf("\n%lld %lld\n", -mn, len - mn);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

