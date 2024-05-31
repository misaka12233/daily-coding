#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int mod = 998244353; 
const int inv2 = mod - mod / 2;
const int inv3 = mod - 1ll * (mod / 3) * ((mod % 3 == 2) ? inv2 : 1) % mod;
ll n, w[N]; 
ll phisum[N];
ll p[N], vis[N], sp1[N], sp2[N], tp, sqrn;

// G的取值为按p为质数时的待求函数值，为完全积性函数，若有不同指数幂则拆分为多个
// sum_G是G的前缀和 
// F的取值为质数的指数幂时的取值 
// 如本题 f(p^k) = p^k(p^k-1) ,则 f(p) = p^2-p, 令 G1(x) = x, G2(x) = x^2
ll G1(ll x){ return 1; }
ll sum_G1(ll x){ return x; } 
ll G2(ll x){ return x; }
ll sum_G2(ll x){ return x * (x + 1) / 2; }
ll F(ll x, ll p){ return x - x / p; } 
// 根据题目需要修改这部分（有可能需要删去g2或添加g3，g的计算完全同理）

// 线性筛出 <= \sqrt{n} 的质数，并求出 p^k 的前缀和
ll fac[15], inv[15];
ll mul(ll a, ll b)
{
	return a * b % mod;
}
ll add(ll a, ll b)
{
	return (a + b) % mod; 
}
ll sub(ll a, ll b)
{
	return (a - b + mod) % mod; 
}
void getP(int m)
{
	vis[1] = 1, phisum[1] = 1;
	for (int i = 2; i <= m; ++i)
	{
		if (vis[i] == 0) p[++tp] = i, phisum[i] = i - 1;
		for (int j = 1; j <= tp && (ll)p[j] * i <= m; ++j)
		{
			vis[i * p[j]] = 1;
			if (i % p[j] == 0)
			{
				phisum[i * p[j]] = phisum[i] * p[j];
				break;
			}
			phisum[i * p[j]] = phisum[i] * phisum[p[j]];
		}
	}
	for (int i = 1; i <= tp; ++i) 
		sp1[i] = (sp1[i - 1] + G1(p[i])) % mod;
	for (int i = 1; i <= tp; ++i) 
		sp2[i] = (sp2[i - 1] + G2(p[i])) % mod;
	for (int i = 1; i <= m; i++)
		phisum[i] = add(phisum[i], phisum[i - 1]);
		
	fac[0] = inv[0] = 1;
	fac[1] = inv[1] = 1;
	for (int i = 2; i <= 10; i++)
	{
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mod - (mod / i) * inv[mod % i] % mod;
	}
	for (int i = 2; i <= 10; i++)
		inv[i] = mul(inv[i], inv[i - 1]);
}
int ind1[N], ind2[N], tot, g1[N], g2[N]; 
unordered_map<ll, ll> saved;
ll S(ll x, int y)
{
	if (y == 0)
	{
		if (x <= 1000000)
			return sub(phisum[x], 1);
		if (saved[x])
			return saved[x];
	}
	if (p[y] >= x) return 0;
	int k = x <= sqrn ? ind1[x] : ind2[n / x];
	ll ans = (1ll * (g2[k] - sp2[y]) - (g1[k] - sp1[y]) + mod + mod) % mod;
	//x内比第y个质数大的质数的贡献，若此前拆分为多个指数幂则需要全部累加
	for (int i = y + 1; i <= tp && (ll)p[i] * p[i] <= x; ++i)
	{
		ll pe = p[i];
		for (int e = 1; pe <= x; ++e, pe *= p[i])
		{
			int xx = pe % mod;
			ans = (ans + F(xx, e) * (S(x / pe, i) + (e != 1)) % mod) % mod;
			// 对于合数，枚举最小质因子次幂，利用积性函数性质提取，递归计算 
		}
	}
	if (y == 0) saved[x] = ans;
	return ans;
}
void calc_g()
{
	// 求出 g(\lfloor\frac{n}{x}\rfloor,0) 的值，并存一下 \lfloor\frac{n}{x}\rfloor 对应的下标
	for (ll l = 1, r, tn; l <= n; l = r + 1)
	{
		r = n / (n / l); 
		w[++tot] = n / l; 
		tn = w[tot] % mod;
		g1[tot] = sum_G1(tn) - 1;
		g2[tot] = sum_G2(tn) - 1;
		if (w[tot] <= sqrn) ind1[w[tot]] = tot;
		else ind2[n / w[tot]] = tot;
	}
	// 根据递归式算出 g(n,j) 的值
	for (int i = 1; i <= tp; ++i)
		for (int j = 1; j <= tot && (ll)p[i] * p[i] <= w[j]; ++j)
		{
			int k = (w[j] / p[i]) <= sqrn ? ind1[w[j] / p[i]] : ind2[n / (w[j] / p[i])];
			(g1[j] -= G1(p[i]) * (g1[k] - sp1[i - 1] + mod) % mod) %= mod;
			(g2[j] -= G2(p[i]) * (g2[k] - sp2[i - 1] + mod) % mod) %= mod;
			(g1[j] += mod) %= mod; 
			(g2[j] += mod) %= mod;
		}
} 

ll qpow(ll a, int b)
{
	ll res = 1;
	while (b)
	{
		if (b & 1) res = mul(res, a);
		a = mul(a, a);
		b >>= 1;
	}
	return res;
}
ll C(int n, int k)
{
	return mul(fac[n], mul(inv[k], inv[n - k]));
}
ll solres(ll n, int k)
{
	ll res = 0;
	for(ll l=1,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        res = add(res, mul(sub(S(r, 0), S(l - 1, 0)), qpow(2, k * (n / l) % (mod - 1))));
    }
    res = sub(res, add(S(n, 0), 1));
    res = mul(2, res);
    res = sub(res, sub(qpow(2, n * k % (mod - 1)), 1));
    ll pk = qpow(2, k), inv = qpow(sub(pk, 1), mod - 2);
    res = mul(res, mul(pk, inv));
    return res;
}
void doit()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        int k;
        scanf("%lld%d", &n, &k);
        calc_g();
        ll ans = (k & 1) ? sub(0, mul(n, n)) : mul(n, n);
        for (int i = 1; i <= k; i++)
        {
        	ll res = solres(n, i);
        	if ((k - i) & 1)
        		ans = sub(ans, mul(res, C(k, i)));
        	else
        		ans = add(ans, mul(res, C(k, i)));
        }
        printf("%lld\n", ans);
    }
}
int main()
{
	getP(1000000);
    doit();
    return 0;
}
