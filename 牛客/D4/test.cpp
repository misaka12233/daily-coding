#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
int x, y;
int cnt[maxn];
vector<int> ans[maxn];
bool dfs(int res, int h)
{
	if (h == y)
	{
		
		return true;
	}
	for (int i = min(n, res); i >= 1; i--)
	{
		if (cnt[i] != 0)
		{
			cnt[i]--;
			if (i == res)
			{
				if (dfs(x, h + 1)) return true;
			}
			else
			{
				if (dfs(res - i, h)) return true;
			}
			cnt[i]++;
		}
	}
	return false;
}
void sol()
{
	scanf("%d", &n);
	int s = 0;
	for (int i = 1; i <= n; i++) 
		s = s + i * (n - i + 1);
	for (int d = sqrt(s); d >= 1; d--)
	{
		if (s % d != 0) continue;
		for (int i = 1; i <= n; i++)
			cnt[i] = n - i + 1;
		x = max(d, s / d);
		y = min(d, s / d);
		if (dfs(x, 0)) return;
	}
}
int main()
{
	int T;
	//freopen("data.in", "r", stdin);
	//freopen("data.out", "w", stdout);
	int lim = 1;
	int l = 0;
	while (lim <= 20000000)
	{
		lim <<= 1;
		l++;
	}
	printf("%d\n", lim);
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

