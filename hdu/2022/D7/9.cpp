#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_SQRTN = 100005;
const int MOD = 1000000007;

int mn_pf[MAX_SQRTN];
int prm[MAX_SQRTN];
int g_p[MAX_SQRTN];
int prm_cnt;

int mp1[MAX_SQRTN], mp2[MAX_SQRTN];
int blk[MAX_SQRTN<<1|5];
int g_b[MAX_SQRTN<<1|5];
int blk_cnt;

int A, n; int sqrtn;
ll inv[31];
ll F[31];

int& addeq(int &a, int b) { a+=b; return a>=MOD?a-=MOD:a; }
int add(int a, int b) { a+=b; return a>=MOD?a-=MOD:a; }
int sub(int a, int b) { a-=b; return a<0?a+=MOD:a; }

ll qpow(ll a, int b = MOD-2, ll r = 1) {
    for (; b; b>>=1, a=a*a%MOD) if (b&1) r=r*a%MOD;
    return r;
}

void prime_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!mn_pf[i]) mn_pf[i] = i, prm[++prm_cnt] = i;
        for (int j = 1; prm[j] <= n/i; ++j) {
            mn_pf[i*prm[j]] = prm[j];
            if (i%prm[j]==0) break;
        }
    }
    for (int i = 1; i <= prm_cnt; ++i) g_p[i] = g_p[i-1]+1;
}

void calc_G(int n) {
    sqrtn = sqrt(n); blk_cnt = 0;
    for (int l = 1, r; l <= n; l = r+1) {
        r = n/(n/l);
        blk[++blk_cnt] = n/l;
        g_b[blk_cnt] = blk[blk_cnt] - 1;
        if (blk[blk_cnt] <= sqrtn) mp1[blk[blk_cnt]] = blk_cnt;
        else mp2[n/blk[blk_cnt]] = blk_cnt;
    }
    
    for (int i = 1; i <= prm_cnt; ++i) 
    for (int j = 1; j <= blk_cnt and prm[i] <= blk[j]/prm[i]; ++j) {
        int x = blk[j]/prm[i] <= sqrtn ? mp1[blk[j]/prm[i]] : mp2[n / (blk[j]/prm[i])];
        g_b[j] -= 1 * (g_b[x] - g_p[i-1]);
    }
}

int calc_S(int x, int y) {
    if (prm[y] >= x) return 0;
    int res = 0;
    
    int id = x<=sqrtn ? mp1[x] : mp2[n/x];
    addeq(res, 1ll*A*sub(g_b[id], g_p[y])%MOD);
    
    for (int i = y+1; i <= prm_cnt and prm[i] <= x/prm[i]; ++i) {
        ll _x = x/prm[i];
        for (int j = 1; _x; ++j, _x /= prm[i]) {
            addeq(res, F[j] * add(calc_S(_x, i), (j!=1)) % MOD);
        }
    }
    return res;
}

void sol() {
    scanf("%d%d", &A, &n); sqrtn = sqrt(n);
    for (int i = 1; i <= 30; ++i) {
        F[i] = 1;
        for (int j = A+i-1; j >= A; --j) F[i] = F[i]*j%MOD;
        for (int j = 2; j <= i; ++j) F[i] = F[i]*inv[j]%MOD;
    }
    calc_G(n);
    int ans = 0;
    int i;
    for (i = 1; i <= prm_cnt && prm[i] * prm[i] <= n; i++)
    	addeq(ans, 1ll * (n/prm[i]) * A %MOD);
    int id = mp2[1];
    addeq(ans, 1ll*A*sub(g_b[id], g_p[i - 1])%MOD);
    addeq(ans, A);
    printf("%d\n", ans);
}

int main() {
    inv[1] = 1; for (int i = 2; i <= 30; ++i) inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
    prime_sieve(100000);
    int _; scanf("%d", &_); while (_--) sol();
    return 0;
}
