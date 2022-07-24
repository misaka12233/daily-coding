#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1000000007;
const ll MOD = 1000000007;

const int draw_tot = 123, draw_max = 39;

int fact[125], ifact[125];
ll dp[125][9];
char str[29];
int cnt[37];

int& addeq(int &a, int b) { a+=b; return a>=MOD?a-=MOD:a; }
ll qkpow(ll a, int b, ll r = 1) {
    for (; b; b>>=1, a=a*a%MOD) if (b&1) r=r*a%MOD;
    return r;
}
ll C(int n, int m) { return 1ll*fact[n]*ifact[m]%MOD*ifact[n-m]%MOD; }

int mp_id(char c1, char c2) {
    if (c2 == 'm') return c1-'0';
    if (c2 == 'p') return c1-'0'+9;
    if (c2 == 's') return c1-'0'+18;
    if (c2 == 'z') return c1-'0'+27;
}

ll sol(int x)
{
	memset(dp, 0, sizeof(dp));
	dp[0][x] = 1;
	for (int i = 0; i < 123; i++)
	{
		for (int j = 0; j <= 6; j++)
		{
			ll res = 13 - 2 * j, tot = 123 - i;
			addeq(dp[i + 1][j], dp[i][j] * (tot - res * 3) % mod * qkpow(tot, mod - 2) % mod);
			addeq(dp[i + 1][j + 1], dp[i][j] * res * 3 % mod * qkpow(tot, mod - 2) % mod);
		}
	}
	ll ans = 0;
	for (int i = 1; i <= 123; i++)
		addeq(ans, dp[i][7] * i % mod);
}


int main() {
    fact[0]=1;
    for (int i = 1; i <= draw_tot; ++i) fact[i] = 1ll*fact[i-1]*i%MOD;
    ifact[draw_tot] = qkpow(fact[draw_tot], MOD-2);
    for (int i = draw_tot-1; ~i; --i) ifact[i] = 1ll*ifact[i+1]*(i+1)%MOD;
    
    sol(0);
    
	return 0;
}

