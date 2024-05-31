#include <bits/stdc++.h>

using namespace std;

using pii = pair<int, int>;
using i64 = long long;

template<typename T> bool chkmn(T &a, T b) { return a>=b ? a=b, 1 : 0; }
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

void sol() {
  i64 x; fast_in >> x;
  int cnt = 0;
  while (x != 1) {
    if (x % 3 == 0) x /= 3;
    else if (x % 2 == 0) x /= 2;
    else --x;
    ++cnt;
  }
  printf("%d\n", cnt);  
}

const int MAX_N = 1000005;
int f[MAX_N];
int g[MAX_N];
void make_table(int n) {
  f[1] = 0, f[2] = 1, f[3] = 1;
  printf("%3d: %3d 00    %3d: %3d /2    %3d: %3d /3    ", 1, f[1], 2, f[2], 3, f[3]);
  for (int i=4; i<=n; ++i) {
    f[i] = f[i-1] + 1;
    g[i] = 0;
    if (i % 2 == 0) {
      if (chkmn(f[i], f[i/2] + 1)) {
        g[i] = 2;
      }
    }
    if (i % 3 == 0) {
      if (chkmn(f[i], f[i/3] + 1))
        g[i] = 1;
    }
    if (chkmn(f[i], f[i-1] + 1)) g[i] = 0;
    if (i <= 999) {
      printf("%3d: %3d ", i, f[i]);
      if (g[i] == 0) {
        putchar('-');
        putchar('1');
      } else if (g[i] == 1) {
        putchar('/');
        putchar('3');
      } else {
        putchar('/');
        putchar('2');
      }
      if (i % 6 != 0) {
        putchar(' ');
        putchar(' ');
        putchar(' ');
        putchar(' ');
      } else {
        putchar('\n');
      }
    }
  }
}

int main() {
  make_table(1000000);
//  int _; fast_in >> _; while (_--)
//    sol();
  return 0;
}
