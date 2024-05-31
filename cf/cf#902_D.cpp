#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int maxn = 100000 + 10;
const int mod = 998244353;
int n;
set<pii> s;
int a[maxn], p[maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", a + i);
		s.insert(pii(-a[i], -i));
	}
	int ans = 0;
	p[0] = 1;
	for (int i = 1; i <= n; i++)
		p[i] = p[i - 1] * 2 % mod;
	while (!s.empty())
	{
		int val = -(*s.begin()).first, pos = -(*s.begin()).second;
		int cnt = 0;
		for (int i = sqrt(pos); i >= 1; i--)
		{
			if (pos % i == 0)
			{
				if (s.find(pii(-a[i], -i)) != s.end())
				{
					s.erase(pii(-a[i], -i));
					cnt++;
				}
				if (i * i != pos)
				{
					int j = pos / i;
					if (s.find(pii(-a[j], -j)) != s.end())
					{
						s.erase(pii(-a[j], -j));
						cnt++;
					}
				}
			}
		}
		ans = (ans + 1ll * val * (p[cnt] - 1) % mod * p[s.size()] % mod) % mod;
	}
	printf("%d\n", ans);
	return 0;
}

