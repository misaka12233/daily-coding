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

const int MAX_N = 500005, MAX_M = 1000005;

struct Edge { int v; char c; };
vector<Edge> e[MAX_N];
bool acceptable[MAX_N];
int n, m, k;

int dfn[MAX_N], low[MAX_N], indx;
int scc_bel[MAX_N], scc_cnt;
bool have_acceptable[MAX_N];
bool have_circle[MAX_N];
void tarjan(int u) {
  static int stk[MAX_N], top = 0;
  stk[++top] = u;
  dfn[u] = low[u] = ++indx;
  for (const auto &[v, _]: e[u]) {
    if (!dfn[v]) {
      tarjan(v);
      chkmn(low[u], low[v]);
    } else if (!scc_bel[v]) {
      chkmn(low[u], dfn[v]);
    }
  }
  if (dfn[u] == low[u]) {
    ++scc_cnt;
    int siz = 0, v; do {
      ++siz;
      v = stk[top--];
      scc_bel[v] = scc_cnt;
      have_acceptable[scc_cnt] |= acceptable[v];
    } while (v != u);
    if (siz != 1) have_circle[scc_cnt] = 1; 
  }
}

vector<int> ee[MAX_N];
int suc_ac[MAX_N];
int dst_scc;
bool chkdfs(int u) {
  int &g = (suc_ac[u] = have_acceptable[u]);
  for (const auto &v: ee[u]) {
    if (!suc_ac[v]) {
      if (chkdfs(v))
        return 1;
    }
    g |= (suc_ac[v] == 1);
  }
  if (g && have_circle[u]) {
    dst_scc = u;
    return 1;
  }
  if (!g) g = 2;
  return 0;
}

char stk[MAX_N]; int top = 0;
bool vis[MAX_N];
int dst_u;

bool reconstruct_lpath(int u) {
  if (scc_bel[u] == dst_scc) {
    dst_u = u;
    for (int i=1; i<=top; ++i) putchar(stk[i]);
    top = 0; return 1;
  }
  vis[u] = 1;
  for (const auto &[v, c]: e[u]) if (!vis[v]) {
    stk[++top] = c;
    if (reconstruct_lpath(v))
      return 1;
    --top;
  } return 0;
}
bool reconstruct_circ(int u) {
  vis[u] = 1;
  for (const auto &[v, c]: e[u]) {
    if (v == dst_u) {
      stk[++top] = c;
      for (int i=1; i<=top; ++i) putchar(stk[i]);
      top = 0; return 1;
    }
    if (!vis[v]) {
      stk[++top] = c;
      if (reconstruct_circ(v))
        return 1;
      --top;
    }
  } return 0;
}
bool reconstruct_rpath(int u) {
  if (acceptable[u]) {
    for (int i=1; i<=top; ++i) putchar(stk[i]);
    top = 0; return 1;
  }
  vis[u] = 1;
  for (const auto &[v, c]: e[u]) if (!vis[v]) {
    stk[++top] = c;
    if (reconstruct_rpath(v))
      return 1;
    --top;
  } return 0;
}

int main() {
  fast_in >> n >> m >> k;
  for (int i=1; i<=k; ++i) {
    int x; fast_in >> x;
    acceptable[x] = 1;
  }
  for (int i=1; i<=m; ++i) {
    int u, v; char c; fast_in >> u >> v >> c;
    e[u].emplace_back(Edge{v, c});
  }
  tarjan(1);
  for (int u=1; u<=n; ++u) {
    int u_id = scc_bel[u];
    for (auto &[v, _]: e[u]) {
      int v_id = scc_bel[v];
      if (u_id != v_id) {
        ee[u_id].emplace_back(v_id);
      } else {
        have_circle[u_id] |= 1;
      }
    }
  }
  if (chkdfs(scc_bel[1])) {
    memset(vis+1, 0, sizeof(int)*n);
    reconstruct_lpath(1);
    memset(vis+1, 0, sizeof(int)*n);
    reconstruct_circ(dst_u);
    memset(vis+1, 0, sizeof(int)*n);
    reconstruct_rpath(dst_u);
    putchar('\n');
  } else {
    puts("-1");
  }
  return 0;
}

