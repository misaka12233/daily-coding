#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
int n;
vector<int> e[maxn];
int dp[maxn][3]; // 0 不选 1 只选自己不选孩子 2 选自己并且选一个孩子 
void dfs(int u, int fa)
{
	int mx = -inf;
	for (auto v : e[u])
	{
		if (v == fa) continue;
		dfs(v, u);
		dp[u][0] += max(dp[v][0], max(dp[v][1], dp[v][2]));
		dp[u][1] += dp[v][0];
		dp[u][2] += dp[v][0];
		mx = max(mx, dp[v][1] - dp[v][0]);
	}
	dp[u][1]++;
	dp[u][2] += mx + 1;
}
void sol()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		e[i].clear();
		dp[i][0] = dp[i][1] = dp[i][2] = 0;
	}
	for (int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	printf("%d\n", max(dp[1][0], max(dp[1][1], dp[1][2])));
}
int main() 
{
    int size(512<<20);
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    int T;
    scanf("%d", &T);
    while (T--)
    {
    	sol();
    }
    exit(0);
}
