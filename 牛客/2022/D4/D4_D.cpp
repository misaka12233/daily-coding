#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 2000000 + 10;
const int maxm = 100000 + 10;
const ll mod = 998244353;
int n, q;

int seed;
ll p[maxn];

int f[11][410][410];
int solve(int a, int b, int c)
{
	int res = 0;
	for (int k = 1; k <= n; k++)
		if (f[k][b][c] <= a)
			res++;
	return res;
}
int main()
{
	memset(f, 0x3f, sizeof(f));
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		int m;
		scanf("%d", &m);
		for (int j = 1; j <= m; j++)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			f[i][b][c] = min(f[i][b][c], a);
		}
	}
	scanf("%d", &seed); 
	std::mt19937 rng(seed);
	std::uniform_int_distribution<> u(1,400);
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= 400; i++)
			for (int j = 1; j <= 400; j++)
				f[k][i][j] = min(f[k][i][j], min(f[k][i - 1][j], f[k][i][j - 1]));
	int lastans=0;
	ll ans = 0;
	p[0] = 1;
	for (int i = 1; i <= q; i++) p[i] = p[i - 1] * seed % mod;
	for (int i=1;i<=q;i++)
	{
	    int IQ=(u(rng)^lastans)%400+1;  // The IQ of the i-th friend
	    int EQ=(u(rng)^lastans)%400+1;  // The EQ of the i-th friend
	    int AQ=(u(rng)^lastans)%400+1;  // The AQ of the i-th friend
	    lastans=solve(IQ,EQ,AQ);  // The answer to the i-th friend
	    ans = (ans + lastans * p[q - i] % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}

