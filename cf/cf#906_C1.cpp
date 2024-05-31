#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef pair<int, int> pii;
int n, m, k;
pii s[maxn];
int cnt[maxn];
int val[maxn];
map<pii, int> res;
void sol()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		cnt[i] = 0;
	res.clear();
	for (int i = 1; i <= m; i++)
	{
		val[i] = 0;
		scanf("%d%d", &s[i].first, &s[i].second);
		cnt[s[i].first]++;
		cnt[s[i].second + 1]--;
	}
	sort(s + 1, s + m + 1);
	int x = 1, y = 1, base = 0;
	for (int i = 1; i <= n; i++)
	{
		cnt[i] = cnt[i - 1] + cnt[i];
		while (x < m && s[x].second < i)
			x++;
		while (y < m && (s[y].second < i || x >= y))
			y++;
		if (cnt[i] == 0)
			base++;
		if (cnt[i] == 1)
			val[x]++;
		if (cnt[i] == 2)
			res[pii(x, y)]++;
	}
	int ans = 0;
	for (auto p : res)
		ans = max(ans, val[p.first.first] + val[p.first.second] + p.second);
	sort(val + 1, val + m + 1);
	ans = max(ans, val[m] + val[m - 1]);
	printf("%d\n", base + ans);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

