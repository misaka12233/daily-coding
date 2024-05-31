#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 10000000 + 10;

struct FastIS {
  static const int LEN = 1<<21|1;
  char buf[LEN], *l, *r, c, *t; bool neof, neg;
  FastIS() : l(buf), r(buf), neof(1) {}
  inline operator bool() { return neof; }
  inline char gc() {
    return
      !neof || (l==r && (r = (l=buf) + fread(buf, 1, LEN, stdin), l==r)) ?
      neof=0, -1 : *l++;
  }
  FastIS& operator>>(char &c) {
    for (c=gc(); isspace(c); c=gc()) {} return *this;
  }
  FastIS& operator>>(char *s) {
    for (c=gc(); isspace(c); c=gc()) {}
    for (t=s; ~c and !isspace(c); c=gc()) *t++=c;
    *t='\0'; return *this;
  }
  template<typename T> FastIS& operator>>(T &x) {
    for (c=gc(); ~c and !isdigit(c); c=gc()) neg ^= (c=='-');
    for (x=0; isdigit(c); c=gc()) x = 10*x+c-'0';
    if (neg) { x=-x, neg=0; } return *this;
  }
} fast_in;

ll ans;
int nxt[maxn];
int len[2][maxn], cnt[maxn];
char s_inv[maxn], t1_inv[maxn];
char s[maxn], t1[maxn], t2[maxn];
void update(int n, int i, int j, int op)
{
	if (op == 0)
		len[0][i - j + 1] = j;
	if (op == 1)
		len[1][n - i + j] = j;
}
void kmp(char *s, char *t, int op)
{
	int n = strlen(s + 1), m = strlen(t + 1);
	for (int i = 2, j = 0; i <= m; i++)
	{
		while (t[j + 1] != t[i] && j != 0) j = nxt[j];
		if (t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
	ll res = 0;
	for(int i = 1, j = 0; i <= n; i++)
	{
		while (t[j + 1] != s[i] && j != 0)
		{
			update(n, i - 1, j, op);
			j = nxt[j];
		}
		if (t[j + 1] == s[i]) j++;
		update(n, i, j, op);
		if (op == 2)
			res = res + cnt[i];
		if (j == m)
		{
			j = nxt[j];
			if (op == 2)
				ans = ans + res;
		}
	}
}
void sol()
{
	fast_in >> (t1 + 1);
	fast_in >> (t2 + 1);
	fast_in >> (s + 1);
	int n = strlen(s + 1), m = strlen(t1 + 1);
	for (int i = 1; i <= n; i++)
	{
		len[0][i] = len[1][i] = cnt[i] = 0;
		s_inv[i] = s[n - i + 1];
	}
	s_inv[n + 1] = '\0';
	for (int i = 1; i <= m; i++)
		t1_inv[i] = t1[m - i + 1];
	t1_inv[m + 1] = '\0';
	kmp(s, t1, 0);
	kmp(s_inv, t1_inv, 1);
	int k = strlen(t2 + 1);
	for (int i = 1; i + m + k - 1 <= n; i++)
	{
		int l = i + m + k - 1 - len[1][i + m + k - 1], r = i + len[0][i] + k - 1;
		if (l <= r)
			cnt[l]++, cnt[r + 1]--;
	}
	ans = 0;
	kmp(s, t2, 2);
	printf("%lld\n", ans);
}
int main()
{
	int T;
	fast_in >> T;
	while (T--) sol();
	return 0;
}

