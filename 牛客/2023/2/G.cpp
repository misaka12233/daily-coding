#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1000005;

int len[MAX_N], diff[MAX_N], slink[MAX_N];
int ch[MAX_N][26], fail[MAX_N];
char tmp[MAX_N], s[MAX_N];
bool f[MAX_N], g[MAX_N];
int indx, last;

bool isvalidletter(char s) {
  return s == 'o' || s == 's' ||
         s == 'x' || s == 'z' ||
         s == 'b' || s == 'q' ||
         s == 'd' || s == 'p' ||
         s == 'n' || s == 'u';
}

bool ismatch(char s, char t) {
  if (s == 'o') return t == 'o';
  if (s == 's') return t == 's';
  if (s == 'x') return t == 'x';
  if (s == 'z') return t == 'z';
  if (s == 'b') return t == 'q';
  if (s == 'q') return t == 'b';
  if (s == 'd') return t == 'p';
  if (s == 'p') return t == 'd';
  if (s == 'n') return t == 'u';
  if (s == 'u') return t == 'n';
  return 0;  
}

int new_node(int l) {
  ++indx;
  memset(ch[indx], 0, sizeof(ch[indx]));
  len[indx] = l;
  return indx;
}
void init() {
  indx = -1; new_node(0); new_node(-1);
  s[0] = '#'; fail[0] = 1; diff[0] = 0; last = 0;
}
int getfail(int p, int i) {
  while (len[p] != -1 && !ismatch(s[i-len[p]-1], s[i])) p = fail[p];
  return p;
}
void insert(int i) {
  int p = getfail(last, i);
  if (!ismatch(s[i-len[p]-1], s[i])) {
    last = 0;
    return;
  }
  if (!ch[p][s[i]-'a']) {
    int q = new_node(len[p]+2);
    fail[q] = ch[getfail(fail[p], i)][s[i]-'a'];
    diff[q] = len[q]-len[fail[q]];
    slink[q] = (diff[q]==diff[fail[q]] ? slink[fail[q]] : fail[q]);
    ch[p][s[i]-'a'] = q;
  }
  last = ch[p][s[i]-'a'];
}

bool sol() {
  scanf("%s", tmp+1); int n = strlen(tmp+1);
  f[0] = 1; init();
  for (int i=1; i<=n; ++i) {
    if (!isvalidletter(tmp[i])) return 0;
    s[i] = tmp[i]; insert(i);
    f[i] = 0;
    for (int x=last; x>1; x=slink[x]) {
      g[x] = f[i-len[slink[x]]-diff[x]];
      if (fail[x] != slink[x]) g[x] |= g[fail[x]];
      f[i] |= g[x];
    }
//    for (int x=last; x>1; x=fail[x])
//      f[i] |= f[i-len[x]];
  }
  return f[n];
}

int main() {
  int _; scanf("%d", &_); while (_--)
    puts(sol() ? "Yes" : "No");
  return 0;
}

