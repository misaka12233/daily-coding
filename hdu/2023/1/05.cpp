#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 100000 + 10;
int T;
int n, m, q;
char s[maxn];
ll h1[maxn], h2[maxn];
void gen(int rk) 
{
	const ll b = 31;
	const ll mod1 = 1e9 + 9;
	const ll mod2 = 1e9 + 7;
	vector<ll> b_pow(n);
	vector<ll> h(n + 1, 0);
	b_pow[0] = 1;
	
	for (int i = 1; i < n; i++) 
		b_pow[i] = (b_pow[i - 1] * b) % mod1;
	for (int i = 0; i < n; i++)
		h[i + 1] = (h[i] * b + s[i] - 'a' + 1) % mod1;
	for (int st = 1; st <= n; st++)
		h1[rk] = max(h1[rk], ((h[st - 1] + (h[n] - h[st - 1] * b_pow[n - st + 1]) % mod1 * b_pow[st - 1] % mod1) % mod1 + mod1) % mod1);
	
	for (int i = 1; i < n; i++) 
		b_pow[i] = (b_pow[i - 1] * b) % mod2;
	for (int i = 0; i < n; i++)
		h[i + 1] = (h[i] * b + s[i] - 'a' + 1) % mod2;
	for (int st = 1; st <= n; st++)
		h1[rk] = max(h1[rk], ((h[st - 1] + (h[n] - h[st - 1] * b_pow[n - st + 1]) % mod2 * b_pow[st - 1] % mod2) % mod2 + mod2) % mod2);
}
int main()
{
	scanf("%d", &T);
	while (T--) 
	{
		scanf("%d%d", &m, &n);
		for (int i = 1; i <= m; i++)
		{
			scanf("%s", s);
			h1[i] = h2[i] = 0;
			gen(i);
		}
		scanf("%d", &q);
		for (int i = 1; i <= q; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (h1[x] == h1[y] && h2[x] == h2[y])
				puts("Yes");
			else
				puts("No");
		}
	}
	return 0;
}

