#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 400000 + 10;
const ll mod = 998244353;

ll fastpow(ll x, ll k)
{
    ll res = 1;
    while (k)
    {
        if (k & 1) res = res * x % mod;
        k >>= 1;
        x = x * x % mod;
    }
    return res;
}
ll g = 3, gi = fastpow(3, mod - 2);
int num[maxn], lim, l;
void NTT(ll *s, bool op)
{
    for (int i = 0; i < lim; i++)
        if (i < num[i])
            swap(s[i], s[num[i]]);
    for (int len = 1; len < lim; len <<= 1)
    {
        ll wn = fastpow(op ? g : gi, (mod - 1) / (len << 1));
        for (int i = 0; i < lim; i += (len << 1))
        {
            ll w = 1;
            for (int j = 0; j < len; j++, w = w * wn % mod)
            {
                ll x = s[i + j], y = w * s[i + j + len] % mod;
                s[i + j] = (x + y) % mod;
                s[i + j + len] = (x - y + mod) % mod;
            }
        }
    }
}
void sol(ll *a, int n, ll *b, int m)
{
    lim = 1;
    l = 0;
    while (lim <= n + m)
    {
        lim <<= 1;
        l++;
    }
    for (int i = 0; i < lim; i++)
        num[i] = (num[i >> 1] >> 1) | ((i & 1) << (l - 1));
    NTT(a, true);
    NTT(b, true);
    for (int i = 0; i < lim; i++)
        a[i] = a[i] * b[i] % mod;
    NTT(a, false);
    ll tmp = fastpow(lim, mod - 2);
    for (int i = 0; i < lim; i++)
        a[i] = a[i] * tmp % mod;
}

int T; 
int n;
ll a[maxn], b[maxn];
ll p[maxn], c[maxn], w[maxn], sum[maxn];
ll t1[maxn], t2[maxn];
void cdq(int l, int r)
{
    if (l == r) return;
    int mid = l + r >> 1;
    cdq(l, mid);
    for (int i = 0; i <= 4 * (r - l); i++) t1[i] = t2[i] = 0;
    for (int i = 0; i <= mid - l; i++)
        t1[i] = a[i + l], t2[i] = w[i];
    for (int i = mid - l + 1; i <= r - l; i++)
        t1[i] = 0, t2[i] = w[i];
    sol(t1, r - l, t2, r - l);
    for (int i = mid + 1; i <= r; i++)
        a[i] = (a[i] + t1[i - l]) % mod;
    a[mid + 1] = a[mid + 1] * (p[mid] - 1 + mod) % mod;
    a[mid + 1] = a[mid + 1] * fastpow(sum[mid + 1], mod - 2) % mod;
    a[mid + 1] = (a[mid + 1] + a[mid]) % mod;
    a[mid + 1] = a[mid + 1] * fastpow(p[mid], mod - 2) % mod;
    for (int i = 0; i <= 4 * (r - l); i++) t1[i] = t2[i] = 0;
    for (int i = 0; i <= mid - l; i++)
        t1[i] = b[i + l], t2[i] = w[i];
    for (int i = mid - l + 1; i <= r - l; i++)
        t1[i] = 0, t2[i] = w[i];
    sol(t1, r - l, t2, r - l);
    for (int i = mid + 1; i <= r; i++)
        b[i] = (b[i] + t1[i - l]) % mod;
    b[mid + 1] = b[mid + 1] * (p[mid] - 1 + mod) % mod;
    b[mid + 1] = b[mid + 1] * fastpow(sum[mid + 1], mod - 2) % mod;
    b[mid + 1] = (b[mid + 1] + b[mid] - c[mid] + mod) % mod;
    b[mid + 1] = b[mid + 1] * fastpow(p[mid], mod - 2) % mod;
    cdq(mid + 1, r);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", p + i, c + i);
            p[i] = p[i] * fastpow(100, mod - 2) % mod;
            a[i] = b[i] = 0;
        }
        a[n] = b[n] = 0;
        for (int i = 2; i <= n; i++)
        {
            scanf("%lld", w + i);
            sum[i] = (sum[i - 1] + w[i]) % mod;
        }
        a[0] = 1;
        b[0] = 0;
        cdq(0, n);
        printf("%lld\n", (mod - b[n]) * fastpow(a[n], mod - 2) % mod);
    }
    return 0;
}

