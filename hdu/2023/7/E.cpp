#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

template<typename T> bool chkmn(T &a, T b) { return a>b ? a=b, 1 : 0; }
template<typename T> bool chkmx(T &a, T b) { return a<b ? a=b, 1 : 0; }
template<typename T> T read() {
  T res = 0; char c = getchar(); bool neg = 0;
  for (; c < '0' || c > '9'; c = getchar()) neg ^= (c == '-');
  for (; c >= '0' && c <= '9'; c = getchar())
    res = 10*res+c-'0';
  return neg ? -res : res;
}

const int MAX_N = 100005;

struct Sam {
	struct Node {
		int ch[26],len,fa;
		Node() : len(0), fa(-1) { memset(ch,-1,sizeof(ch)); }
	} st[MAX_N<<1];
	int lst, num;
	Sam() : lst(0), num(1) { memset(st[0].ch, -1, sizeof(st[0].ch)); }
	void ins(int w) {
		int cur=num++;
		memset(st[cur].ch, -1, sizeof(st[cur].ch));
		st[cur].len=st[lst].len+1;
		int p=lst;
		for(; ~p and st[p].ch[w]==-1; p=st[p].fa) st[p].ch[w]=cur;
		if(p==-1) st[cur].fa=0;
		else{
			int q=st[p].ch[w];
			if(st[q].len==st[p].len+1) st[cur].fa=q;
			else{
				int clone=num++;
				memcpy(st[clone].ch,st[q].ch,sizeof(st[q].ch));
				st[clone].len=st[p].len+1;
				st[clone].fa=st[q].fa;
				for(; ~p and st[p].ch[w]==q; p=st[p].fa) st[p].ch[w]=clone;
				st[q].fa=st[cur].fa=clone;
			}
		}
		lst=cur;
	}
	void bld(char s[],int n) { for(int i=0; i<n; ++i) ins(s[i]-'a'); }
} sam;

stack<char> stk;
int nxt[MAX_N][26], last[26];

bool dfs(int psuf, int pseq) {
  for (int i=0; i<26; ++i) {
    int _pseq = nxt[pseq][i];
    if (_pseq == -1) continue;
    int _psuf = sam.st[psuf].ch[i];
    if (_psuf == -1) {
      stk.push('a'+i);
      return 1;
    } else {
      if (dfs(sam.st[psuf].ch[i], nxt[pseq][i])) {
        stk.push('a'+i);
        return 1;
      }
    }
  }
  return 0;
}

char s[MAX_N];
void solababa() 
{
	printf("jin lai le\n");
  scanf("%s", s+1); 
  int n = strlen(s+1);
  sam();
  sam.bld(s+1, n);
  for (int i=0; i<26; ++i) last[i] = -1;
  for (int i=n; i>=0; --i) {
    for (int j=0; j<26; ++j) nxt[i][j] = last[j];
    last[s[i]-'a'] = i;
  }
  if (dfs(0, 0)) {
    while (!stk.empty()) {
      putchar(stk.top());
      stk.pop();
    }
    putchar('\n');
  } else {
    puts("-1");
  }
}

int main() {
	freopen("test.in", "r", stdin);
  int _;
  scanf("%d", &_); 
  while (_--) 
  {
  	printf("%d\n", _);
  	solababa();
  }
  return 0;
}

