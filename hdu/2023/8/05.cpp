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

int sol() {
  static const int MAX_N = 100005;
  static char s[MAX_N];
  int n; fast_in >> n >> s;
  int l = 0, r = n-1;
  bool cur_player = 0;
  while (l <= r) {
    bool able_l = s[l] == '0'+cur_player;
    bool able_r = s[r] == '0'+cur_player;
    if (!able_l && !able_r) return cur_player ^ 1;
    if (!able_l) { --r; cur_player ^= 1; continue; }
    if (!able_r) { ++l; cur_player ^= 1; continue; }
    if (l == r) return -1;
    if (l+1 <= r && s[l+1] == '0'+cur_player) return cur_player;
    if (r-1 >= l && s[r-1] == '0'+cur_player) return cur_player;
    if (r-l+1 <= 4) return -1;
    able_l = s[l+2] == '0'+cur_player;
    able_r = s[r-2] == '0'+cur_player;
    if (!able_l && !able_r) return cur_player ^ 1;
    if (!able_l) { r -= 2; continue; }
    if (!able_r) { l += 2; continue; }
    return r-l+1 == 5 ? -1 : cur_player;
  }
  return -1;
}

int main() {
  int _; fast_in >> _; while (_--)
    printf("%d\n", sol());
  return 0;
}
