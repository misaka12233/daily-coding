#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull, ull> pll;
const int maxn = 300000 + 5;

namespace pam {
int sz, tot, last;
int cnt[maxn], ch[maxn][26], len[maxn], fail[maxn];
ull p[2][maxn];
pll has[maxn];
ull B1, B2, mod;
char s[maxn];
map<pll, int> mp;
int ans;

void ini(int n) {
	B1 = 233;
	B2 = 31;
	mod = 1e9 + 7;
	ans = 0;
	p[0][0] = p[1][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		p[0][i] = p[0][i] * B1;
		p[1][i] = p[1][i] * B2 % mod;
	}
}

int node(int l, pll h) {  // 建立一个新节点，长度为 l
  sz++;
  memset(ch[sz], 0, sizeof(ch[sz]));
  len[sz] = l;
  fail[sz] = cnt[sz] = 0;
  has[sz] = h;
  return sz;
}

void clear() {  // 初始化
  sz = -1;
  last = 0;
  s[tot = 0] = '$';
  node(0, {0, 0});
  node(-1, {0, 0});
  fail[0] = 1;
}

int getfail(int x) {  // 找后缀回文
  while (s[tot - len[x] - 1] != s[tot]) x = fail[x];
  return x;
}

void insert(char c) {  // 建树
  s[++tot] = c;
  int now = getfail(last);
  if (!ch[now][c - 'a']) {
  	
    int x = node(len[now] + 2, 
	{has[now].first * B1 + c + p[0][len[now] + 1] * c, 
	(has[now].second * B2 % mod + c + p[1][len[now] + 1] * c % mod) % mod});
	
    fail[x] = ch[getfail(fail[now])][c - 'a'];
    ch[now][c - 'a'] = x;
  }
  last = ch[now][c - 'a'];
  cnt[last]++;
}

void solve(int k) {
  for (int i = sz; i >= 0; i--) {
    cnt[fail[i]] += cnt[i];
  }
  for (int i = 1; i <= sz; i++) {  // 更新答案
    mp[has[i]]++;
    if (mp[has[i]] == k) 
    	ans++;
  }
}

int getans() { return ans; }
}  // namespace pam

char s[maxn];

int main() {
	pam::ini(300000);
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= k; i++)
	{
		pam::clear();
		scanf("%s", s + 1);
		for (int i = 1; s[i]; i++)
			pam::insert(s[i]);
		pam::solve(k);
	}
	printf("%d\n", pam::getans() - 1);
	return 0;
}
