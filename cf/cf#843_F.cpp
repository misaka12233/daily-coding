#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 700;
ll mod;
ll dp[N][N];
ll sum[N][N];
ll res[N];
void sol(int op)
{
	int n;
	scanf("%d", &n);
	ll base = sqrt(n);
	ll p1, p2;
	if (base * base == n)
		p1 = p2 = base;
	else if (base * base < n && n <= base * (base + 1))
		p1 = base + 1, p2 = base;
	else
		p1 = p2 = base + 1;
	if (op == 1)
	{
		printf("%lld %lld\n", p1, p2);
		int cnt = p1 * p2 - n;
		for (int i = 1; i <= p1; i++)
		{
			for (int j = 1; j <= p2; j++)
			{
				if (cnt > 0)
				{
					cnt--;
					printf(".");
				}
				else
					printf("#");
			}
			printf("\n");
		}
	}
	else
	{
		ll ans = 0;
		for (ll x = 1; x < p1 + p2; x++)
		{
			ll y = p1 + p2 - x;
			if (x * y >= n)
				ans = (ans + res[x * y - n]) % mod;
		}
		printf("%lld %lld\n", (p1 + p2) * 2, ans);
	}
}
int main()
{
	int T, op;
	scanf("%d%d", &T, &op);
	if (op == 2)
	{
		scanf("%lld", &mod);
		sum[0][0] = 1;
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < N; j++)
			{
				if (j <= i)
					dp[i][j] = sum[i - j][j];
				sum[i][j] = (sum[i][j - 1] + dp[i][j]) % mod;
			}
		}
		res[0] = 1;
		for (int i = 1; i <= 4; i++)
			for (int j = N - 1; j >= 0; j--)
				for (int k = 1; k <= j; k++)
					res[j] = (res[j] + res[j - k] * sum[k][N - 1] % mod) % mod;
	}
	while (T--) sol(op);
	return 0;
}


