#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

const int MAX_M = 200005, MAX_T = 800005;
const ll INF = 0x7fffffffffffffff;

int advi[MAX_T];
ll res[MAX_M];
int w[MAX_M];
ll g[MAX_M];
ll c[MAX_M];
int m;

#define lc ((p)<<1)
#define rc ((p)<<1|1)
#define mid (((l)+(r))>>1)
inline ll calc(int i, int j) { return res[i]+(c[j]-c[i])*w[i]; }
void upd(int ql, int qr, int i, int p=1, int l=1, int r=m) {
    if (ql <=l and r <= qr) {
        if (!advi[p]) { advi[p] = i; return; }
        if (calc(i, mid) <  calc(advi[p], mid)) swap(i, advi[p]);
        if (calc(i, l) < calc(advi[p], l)) upd(ql, qr, i, lc, l, mid);
        else if (calc(i, r) < calc(advi[p], r)) upd(ql, qr, i, rc, mid+1, r);
    } else {
        if (ql<=mid) upd(ql, qr, i, lc, l, mid);
        if (qr>mid) upd(ql, qr, i, rc, mid+1, r);
    }
}
ll qry(int x, int p=1, int l=1, int r=m) {
    ll res = INF;
    if (advi[p]) res = min(res, calc(advi[p], x));
    if (l==r) return res;
    if (x <= mid) return min(res, qry(x, lc, l, mid));
    else return min(res, qry(x, rc, mid+1, r));
}
#undef lc
#undef rc
#undef mid

int main() {
    int k, v; scanf("%d%d%d", &m, &k, &v);
    for (int i=1; i<=m; ++i) { scanf("%lld", &g[i]); g[i] += g[i-1]; }
    for (int i=1; i<=m; ++i) scanf("%d", &w[i]);
    for (int i=1; i<=m; ++i) g[i] = (g[i]+v-1) / v;
    c[m] = g[m];
    for (int i=m-1; i; --i) {
        if (g[i]==g[i+1]) { c[i] = c[i+1], w[i] = w[i+1]; }
        else { c[i] = g[i+1]-1; }
    }
    for (int i=2; i<=m; ++i) res[i] = INF;
    res[1] = w[1]*c[1];
    for (int i=1; i<=m; ++i) {
        if (i>1 and g[i]==g[i-1]) { res[i]=min(res[i], res[i-1]); continue; }
        res[i] = min(res[i], qry(i));
        int l=i, r=m;
        while (l<r) {
            int t = (l+r+1)>>1;
            if (c[t]-c[i] <= k) l=t;
            else r=t-1;
        }
        if (r>i) upd(i+1, r, i);
        if (r<m and c[r]-c[i] < k) {
            res[r+1] = min(res[r+1], res[i]+k*w[i]+(c[r+1]-c[i]-k)*w[r+1]);
        }
    }
    printf("%lld\n", res[m]);
    return 0;
}
