#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re register
#define debug printf("Now is Line : %d\n",__LINE__)
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define ll long long
#define mod 998244353
#define maxn 5000000
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
ll pai[maxn+5];
int prim[maxn+5],cnt;
bool vis[maxn+5];
unordered_map<ll,ll> ans_pai;
ll fac[15], inv[15];
il void init()
{
    pai[1]=1;
    for(re int i=2;i<=maxn;++i)
    {
        if(!vis[i]) prim[++cnt]=i,pai[i]=i-1;
        for(re int j=1;j<=cnt&&prim[j]*i<=maxn;++j)
        {
            vis[prim[j]*i]=1;
            if(i%prim[j]==0)
            {
                pai[i*prim[j]]=pai[i]*prim[j];
                break;
            }
            pai[i*prim[j]]=pai[prim[j]]*pai[i];
        }
    }
    for(re int i=1;i<=maxn;++i) pai[i]=add(pai[i], pai[i-1]);
    
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
il ll get_pai(ll x)
{
    if(x<=maxn) return pai[x];
    if(ans_pai[x]) return ans_pai[x];
    ll ans= (((1+x)*x)/2) % mod;
    for(re ll l=2,r;l<=x;l=r+1)
    {
        r=x/(x/l);
        ans=sub(ans,mul((r-l+1),get_pai(x/l)));
    }
    return ans_pai[x]=ans;
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
il ll C(int n, int k)
{
	return mul(fac[n], mul(inv[k], inv[n - k]));
}
ll solres(ll n, int k)
{
	ll res = 0;
	for(ll l=1,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        res = add(res, mul(sub(get_pai(r), get_pai(l - 1)), qpow(2, k * (n / l) % (mod - 1))));
    }
    res = sub(res, get_pai(n));
    res = mul(2, res);
    res = sub(res, sub(qpow(2, n * k % (mod - 1)), 1));
    ll pk = qpow(2, k), inv = qpow(sub(pk, 1), mod - 2);
    res = mul(res, mul(pk, inv));
    return res;
}
il void doit()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        get_pai(n);
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
signed main()
{
    init(),doit();
    return 0;
}
