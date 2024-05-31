#include<bits/stdc++.h>
using namespace std;
const int maxn = 300 + 10;
const int maxm = 60000 + 10;
typedef long long ll;
const ll mod0 = 1000000007;
const ll mod1 = 1000000009;
const ll P = 131;
int n, q, m, k;
char s[maxn][maxm], t[maxm];
ll Pk[2][maxm];
ll h[2][maxn][maxm], v[2][maxm];
void calc(char *s, ll* h0, ll *h1)
{
	for (int i = 1; i <= m; i++)
	{
		h0[i] = h0[i - 1] * P % mod0 + s[i];
		h1[i] = h1[i - 1] * P % mod1 + s[i];
	}
}
bool check(int l, int r, int id)
{
	ll x = (v[0][r] - v[0][l - 1] * Pk[0][r - l + 1] % mod0 + mod0) % mod0;
	ll y = (h[0][id][r] - h[0][id][l - 1] * Pk[0][r - l + 1] % mod0 + mod0) % mod0;
	if (x != y) return false;
	x = (v[1][r] - v[1][l - 1] * Pk[1][r - l + 1] % mod1 + mod1) % mod1;
	y = (h[1][id][r] - h[1][id][l - 1] * Pk[1][r - l + 1] % mod1 + mod1) % mod1;
	if (x != y) return false;
	return true;
}
int main()
{
	scanf("%d%d%d%d", &n, &q, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i] + 1);
		calc(s[i], h[0][i], h[1][i]);
	}
	Pk[0][0] = Pk[1][0] = 1;
	for (int i = 1; i <= m; i++)
	{
		Pk[0][i] = Pk[0][i - 1] * P % mod0;
		Pk[1][i] = Pk[1][i - 1] * P % mod1;
	}
	while (q--)
	{
		scanf("%s", t + 1);
		calc(t, v[0], v[1]);
		int res = 0;
		for (int i = 1; i <= n; i++)
		{
			int st = 0;
			for (int j = 0; j <= k; j++)
			{
				st++;
				int l = st, r = m + 1;
				while (l < r)
				{
					int mid = l + r >> 1;
					if (check(st, mid, i)) l = mid + 1;
					else r = mid;
				}
				st = l;
				if (st == m + 1)
					break; 
			}
			if (st == m + 1)
				res++;
		}
		printf("%d\n", res);
	}
	return 0;
}

