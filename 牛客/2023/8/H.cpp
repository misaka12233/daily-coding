#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

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

const int MAX_N = 1000005;

namespace FHQTreap {
int val[MAX_N], rnd[MAX_N];
int lc[MAX_N], rc[MAX_N], siz[MAX_N];
int indx = 0;

inline int new_node(int v) {
  ++indx;
  val[indx] = v; rnd[v] = rand();
  lc[indx] = rc[indx] = 0; siz[indx] = 1;
  return indx;
}
inline void push_up(int p) { siz[p] = siz[lc[p]] + siz[rc[p]] + 1; }
void split(int p, int v, int &x, int &y) {
  if (!p) { x = y = 0; return; }
  if (val[p] <= v) x = p, split(rc[p], v, rc[p], y);
  else y = p, split(lc[p], y, x, lc[p]);
  push_up(p);
}
int merge(int x, int y) {
  if (!x || !y) return x | y;
  if (rnd[x] <= rnd[y]) {
    rc[x] = merge(rc[x], y);
    push_up(x); return x;
  } else {
    lc[y] = merge(x, lc[y]);
    push_up(y); return y;
  }
}
int merge_v(int x, int y) {
  if (!x || !y) return x | y;
  if (rnd[x] > rnd[y]) swap(x, y);
  int ly, ry; split(y, val[x], ly, ry);
  lc[x] = merge_v(lc[x], ly);
  rc[x] = merge_v(rc[x], ry);
  push_up(x); return x;
}
}  // namespace FHQTreap

int a[MAX_N], n;
int root[MAX_N];
int R[MAX_N];

int main() {
  srand(time(NULL));
  using namespace FHQTreap;
  ll res = 0;
  fast_in >> n;
  for (int l=1; l<=n; ++l) fast_in >> a[l];
  for (int l=n; l>=1; --l) if (a[l] == 1) {
    root[l] = new_node(1);
    int &r = R[l]; r = l;
    while (r < n) {
      if (a[r+1] == 1) {
        root[l] = merge_v(root[l], root[r+1]);
        r = R[r+1];
      } else {
        int x, y, z;
        split(root[l], a[r+1]-1, y, z);
        split(y, a[r+1]-2, x, y);
        if (siz[y]) {
          root[l] = merge(x, merge(merge(lc[y], rc[y]), merge(new_node(a[r+1]), z)));
          ++r;
        } else {
          root[l] = merge(x, merge(y, z));
          break;
        }
      }
    }
    // printf("[%d, %d]\n", l, r);
    res += r-l+1;
  }
  printf("%lld\n", res);
  return 0;
}

