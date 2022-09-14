#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e6 + 10;
const int mod = 1e9 + 7; 
const int inv2 = mod - mod / 2;
const int inv3 = mod - 1ll * (mod / 3) * ((mod % 3 == 2) ? inv2 : 1) % mod;
ll n, w[N]; 
ll p[N], vis[N], sp1[N], sp2[N], tp, sqrn;

// G的取值为按p为质数时的待求函数值，为完全积性函数，若有不同指数幂则拆分为多个
// sum_G是G的前缀和 
// F的取值为质数的指数幂时的取值 
// 如本题 f(p^k) = p^k(p^k-1) ,则 f(p) = p^2-p, 令 G1(x) = x, G2(x) = x^2
ll G1(ll x){ return 1; }
ll sum_G1(ll x){ return x; } 
ll G2(ll x){ return x; }
ll sum_G2(ll x){ return x * (x + 1) / 2; }
ll F1(ll x, ll k){ return ((k >= 2) ? 0 : - 1); } 
ll F2(ll x, ll p){ return x - x / p; } 
// 根据题目需要修改这部分（有可能需要删去g2或添加g3，g的计算完全同理）

// 线性筛出 <= \sqrt{n} 的质数，并求出 p^k 的前缀和
void getP(int m)
{
	vis[1] = 1;
	for (int i = 2; i <= m; ++i)
	{
		if (!vis[i]) p[++tp] = i;
		for (int j = 1; j <= tp && (ll)p[j] * i <= m; ++j)
		{
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
	for (int i = 1; i <= tp; ++i) 
		sp1[i] = sp1[i - 1] + G1(p[i]);
	for (int i = 1; i <= tp; ++i) 
		sp2[i] = sp2[i - 1] + G2(p[i]);
}
ll ind1[N], ind2[N], tot, g1[N], g2[N]; 
ll S1(ll x, int y)
{
	if (p[y] >= x) return 0;
	ll k = x <= sqrn ? ind1[x] : ind2[n / x];
	ll ans = - (g1[k] - sp1[y]);
	//x内比第y个质数大的质数的贡献，若此前拆分为多个指数幂则需要全部累加
	for (int i = y + 1; i <= tp && (ll)p[i] * p[i] <= x; ++i)
	{
		ll pe = p[i];
		for (int e = 1; pe <= x; ++e, pe *= p[i])
		{
			int xx = pe;
			ans += F1(xx, e) * (S1(x / pe, i) + (e != 1));
			// 对于合数，枚举最小质因子次幂，利用积性函数性质提取，递归计算 
		}
	}
	return ans;
}
ll S2(ll x, int y)
{
	if (p[y] >= x) return 0;
	ll k = x <= sqrn ? ind1[x] : ind2[n / x];
	ll ans = (g2[k] - sp2[y]) - (g1[k] - sp1[y]);
	//x内比第y个质数大的质数的贡献，若此前拆分为多个指数幂则需要全部累加
	for (int i = y + 1; i <= tp && (ll)p[i] * p[i] <= x; ++i)
	{
		ll pe = p[i];
		for (int e = 1; pe <= x; ++e, pe *= p[i])
		{
			int xx = pe;
			ans += F2(xx, p[i]) * (S2(x / pe, i) + (e != 1));
			// 对于合数，枚举最小质因子次幂，利用积性函数性质提取，递归计算 
		}
	}
	return ans;
}
void calc_g()
{
	// 求出 g(\lfloor\frac{n}{x}\rfloor,0) 的值，并存一下 \lfloor\frac{n}{x}\rfloor 对应的下标
	for (ll l = 1, r, tn; l <= n; l = r + 1)
	{
		r = n / (n / l); 
		w[++tot] = n / l; 
		tn = w[tot];
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
			g1[j] -= G1(p[i]) * (g1[k] - sp1[i - 1]);
			g2[j] -= G2(p[i]) * (g2[k] - sp2[i - 1]);
		}
} 
ll qry[15];
int main()
{
	int T;
	scanf("%d", &T); 
	ll mx = 0;
	for (int i = 1; i <= T; i++)
	{
		scanf("%lld", qry + i); 
		mx = max(qry[i], mx);
	}
	sqrn = sqrt(mx); 
	getP(sqrn);
	for (int i = 1; i <= T; i++)
	{
		n = qry[i];
		sqrn = sqrt(n);
		tot = 0;
		calc_g();
		printf("%lld %lld\n", S2(n, 0) + 1, (S1(n, 0) + 1));
	}
	return 0;
}

