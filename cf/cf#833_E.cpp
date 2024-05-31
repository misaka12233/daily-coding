#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
const int mod = 1e9 + 7;
int T;
int n, m;
vector<int> e[maxn];
int sta[maxn], top;
int val[maxn];
vector<int> dp[maxn]; 
int ans;
int mul(ll x, ll y) { return x * y % mod; }
void dfs(int x)
{
	for (int i = 0; i <= m; i++)
		dp[x].push_back(0);
	int sum = 1;
	for (auto y : e[x])
	{
		dfs(y);
		for (int i = 1; i <= m; i++)
		{
			sum = (sum + dp[x][i]) % mod;
			dp[x][i] = mul(sum, dp[y][i]);
		}
		sum = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int now = dp[x][i];
		dp[x][i] = sum;
		sum = (sum + now) % mod;
	}
	if (x == n) ans = sum;
}
void sol()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + 1; i++)
	{
		e[i].clear();
		dp[i].clear();
	}
	top = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", val + i);
		while (top > 0 && val[sta[top]] < val[i])
		{
			e[i].push_back(sta[top]);
			top--;
		}
		sta[++top] = i;
	}
	n++;
	while (top > 0)
	{
		e[n].push_back(sta[top]);
		top--;
	}
	dfs(n);
	printf("%d\n", ans);
}
int main()
{
	scanf("%d", &T);
	while (T--)	sol();
	return 0;
}

