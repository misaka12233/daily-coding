#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;

const int MAX_M = 200005, MAX_T = 800005;
const ll INF = 0x7fffffffffffffff;

ll res[MAX_M];
int w[MAX_M];
ll g[MAX_M];
ll c[MAX_M];
int m;

int main() {
    int k, v; scanf("%d%d%d", &m, &k, &v);
    for (int i=1; i<=m; ++i) { scanf("%lld", &g[i]); g[i] += g[i-1]; }
    for (int i=1; i<=m; ++i) scanf("%d", &w[i]);
    for (int i=1; i<=m; ++i) g[i] = (g[i]+v-1) / v;
    int len = 0;
    for (int i=1; i<=m; ++i)
    {
    	while (g[i] == g[i + 1] && i + 1 <= m) i++;
    	len++;
    	g[len] = g[i];
    	w[len] = w[i];
    }
    m = len;
    c[m] = g[m];
    for (int i=m-1; i; --i) 
   		c[i] = g[i+1]-1;
    for (int i=2; i<=m; ++i) res[i] = INF;
    res[1] = w[1]*c[1];
    for (int i=1; i<=m; ++i) 
	{
		int j;
        for (j=i+1; j<=m && c[j] - c[i] <= k; j++)
        	res[j] = min(res[j], res[i] + (c[j] - c[i]) * w[i]);
        if (c[j - 1] - c[i] < k)
        	res[j] = min(res[j], res[i] + 1ll * k * w[i] + (c[j] - c[i] - k) * w[j]);
    }
    printf("%lld\n", res[m]);
    return 0;
}
