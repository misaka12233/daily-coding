#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
typedef pair<int, int> pii;
int n, m, k;
multiset<pii> s;
vector<pii> add[maxn], remov[maxn];
int dp[maxn][11][18];
int getval(int l, int r, int j)
{
	int t = log(r - l + 1) / log(2);
	return max(dp[l][j][t], dp[r - (1 << t) + 1][j][t]);
}
void sol()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		add[i].clear();
		remov[i].clear();
	}
	s.clear();
	for (int i = 1; i <= m; i++)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		add[l].push_back(pii(l, r));
		remov[r + 1].push_back(pii(l, r));
	}
	for (int i = 1; i <= n; i++)
	{
		for (auto x : add[i])
			s.insert(x);
		for (auto x : remov[i])
			s.erase(x);
		for (int j = 0; j <= k; j++)
		{
			dp[i][j][0] = 0;
			if (s.size() <= j)
			{
				int l = 0, r = -1, cnt = s.size();
				auto it = s.begin();
				while (it != s.end())
				{
					r = (*it).first - 1;
					dp[i][j][0] = max(dp[i][j][0], 1 + getval(l, r, j - cnt));
					while (it != s.end() && (*it).first - 1 == r)
					{
						it++;
						cnt--;
					}
					l = r + 1;
				}
				if (l < i)
					dp[i][j][0] = max(dp[i][j][0], 1 + getval(l, i - 1, j));
			}
			int t = 1;
			while (i - (1 << t) + 1 >= 0)
			{
				dp[i - (1 << t) + 1][j][t] = max(dp[i - (1 << t) + 1][j][t - 1], dp[i - (1 << (t - 1)) + 1][j][t - 1]);
				t++;
			}
		}
	}
	printf("%d\n", getval(1, n, k));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

