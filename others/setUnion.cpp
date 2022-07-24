#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int n, m;
set<int> s[maxn];
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		s[min(x, y)].insert(max(x, y));
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!s[i].empty())
		{
			ans = ans + s[i].size();
			int fir = *s[i].begin();
			s[i].erase(s[i].begin());
			if (s[i].size() > s[fir].size())
				s[i].swap(s[fir]);
			s[fir].insert(s[i].begin(), s[i].end());
		}
	}
	printf("%lld\n", ans);
	return 0;
}

