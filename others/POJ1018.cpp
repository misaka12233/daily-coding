#include <cstdio>
#include <iostream>
#include <set>
#include <queue>
using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> pip;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
multiset<pii> s[maxn];
priority_queue<pip> all_q;
int n;
void sol()
{
	scanf("%d", &n);
	while (!all_q.empty()) all_q.pop();
	for (int i = 1; i <= n; i++)
	{
		int m;
		scanf("%d", &m);
		s[i].clear();
		for (int j = 1; j <= m; j++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			all_q.push(pip(pii(-x, y), i));
			s[i].insert(pii(y, x));
		}
	}
	int p = 0;
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		pii tmp = *s[i].begin();
		p += tmp.first;
	}
	while (!all_q.empty())
	{
		pip now = all_q.top();
		all_q.pop();
		ans = max(ans, (double)-now.first.first / p);
		p -= now.first.second;
		s[now.second].erase(pii(now.first.second, -now.first.first));
		if (!s[now.second].empty())
		{
			pii tmp = *s[now.second].begin();
			p += tmp.first;
		}
		else break;
	}
	printf("%.3f\n", ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

