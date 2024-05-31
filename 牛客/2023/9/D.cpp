#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using i64 = long long;

template<typename T> bool chkmn(T &a, T b) { return a>b ? a=b, 1 : 0; }
template<typename T> bool chkmx(T &a, T b) { return a<b ? a=b, 1 : 0; }
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

const int MAX_N = 5005;
int a[MAX_N];
int nxt[MAX_N][MAX_N];
int d[MAX_N], now[MAX_N];

int sol() {
	int res = 0;
	int n; fast_in >> n;
	for (int i=1; i<=n; ++i)
		fast_in >> a[i];
	
	for (int x = 1; x <= n; x++)
	{
		int lst = n + 1;
		for (int i = n; i >= 1; i--)
		{
			nxt[x][i] = 0;
			if (a[i] <= x) 
				nxt[x][i] = lst, lst = i;
		}
	}
	for (int l=n; l>=1; --l) 
	{
		for (int r=l; r<=n; ++r) d[r] = 0;
		now[l] = l;
		for (int r = l; r <= n; r++)
		{
			if (a[l] > a[r])
				now[r] = nxt[a[r]][now[r]];
			d[now[r]]++;
			d[nxt[a[r]][now[r]]]--;
		}
		for (int r=l, g = 0; r<=n; ++r) 
		{
			g += d[r];
			res += g == 0;
		}
	}
	return res;
}

int main() {
  int _; fast_in >> _; while (_--)
    printf("%d\n", sol());
  return 0;
}

