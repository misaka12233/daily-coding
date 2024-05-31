#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;

struct state{
  int len, link;
  std::map<char, int> next;
};
state st[maxn * 2];
int sz, last;
void sam_init() 
{
	st[0].len = 0;
	st[0].link = -1;
	sz++;
	last = 0;
}
void sam_extend(char c) 
{
	int cur = sz++;
	st[cur].len = st[last].len + 1;
	int p = last;
	while (p != -1 && !st[p].next.count(c)) 
	{
		st[p].next[c] = cur;
		p = st[p].link;
	}
	if (p == -1) 
		st[cur].link = 0;
	else
	{
		int q = st[p].next[c];
	    if (st[p].len + 1 == st[q].len)
	      	st[cur].link = q;
		else 
		{
	    	int clone = sz++;
	    	st[clone].len = st[p].len + 1;
	    	st[clone].next = st[q].next;
	    	st[clone].link = st[q].link;
	    	while (p != -1 && st[p].next[c] == q) 
			{
	    		st[p].next[c] = clone;
	        	p = st[p].link;
	    	}
	      	st[q].link = st[cur].link = clone;
	    }
	}
	last = cur;
}

int n, m, k;
char a[maxn], b[maxn];
ll sum[maxn], mn[maxn][17];
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	scanf("%s", a);
	sam_init();
	for (int i = 0; i < n; i++)
		sam_extend(a[i]);
	for (int i = 1; i <= m; i++)
	{
		scanf("%lld", sum + i);
		sum[i] += sum[i - 1];
		mn[i][0] = sum[i];
	}
	for (int l = 1, len = 1; l <= 16; l++, len <<= 1)
		for (int i = 0; i + 2 * len - 1 <= n; i++)
			mn[i][l] = min(mn[i][l - 1], mn[i + len][l - 1]);
	while (k--)
	{
		scanf("%s", b + 1);
		int v = 0, l = 0;
		ll ans = 0;
		for (int i = 1; i <= m; i++)
		{
			while (st[v].link != -1 && !st[v].next.count(b[i]))
			{
				v = st[v].link;
				l = st[v].len;
			}
			if (st[v].next.count(b[i]))
			{
				v = st[v].next[b[i]];
				l++;
			}
			int t = log(l + 1) / log(2);
			int len = 1 << t;
			ans = max(ans, sum[i] - min(mn[i - l][t], mn[i - len + 1][t]));
		}
		printf("%lld\n", ans);
	}
	return 0;
}

