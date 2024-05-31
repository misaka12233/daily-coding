#include <bits/stdc++.h>

using namespace std;

template<typename T> bool chkmn(T &a, T b) { return a>b ? a=b, 1 : 0; }
template<typename T> T read() {
  T res = 0; char c = getchar(); bool neg = 0;
  for (; c < '0' || c > '9'; c = getchar()) neg ^= (c == '-');
  for (; c >= '0' && c <= '9'; c = getchar())
    res = 10*res+c-'0';
  return neg ? -res : res;
}

const int MAX_K = 1000005, MAX_N = 4000005;

struct Info {
  int v, id;
  bool operator<(const Info& rhs) const {
    return v < rhs.v;
  }
} a[MAX_N];
int mn[MAX_K];
int head, tail;
int pre[MAX_K], nxt[MAX_K];

void sol() {
  int k = read<int>(), num = 0;
  for (int i=1; i<=k; ++i) {
    int c = read<int>();
    while (c--)
      a[++num] = Info({read<int>(), i});
  }
  int res = 2000000000;
  head = 1;
  tail = k;
  for (int i=1; i<=k; ++i)
  {
  	mn[i] = -1000000001;
  	pre[i] = i - 1;
  	nxt[i] = i + 1;
  }

  sort(a+1, a+num+1);
  for (int i=1; i<=num; ++i) {
  	mn[a[i].id] = a[i].v;
  	
  	if (a[i].id != tail)
  	{
  		if (head == a[i].id) head = nxt[a[i].id];
  		
  		nxt[pre[a[i].id]] = nxt[a[i].id];
  		pre[nxt[a[i].id]] = pre[a[i].id];
  		
  		pre[a[i].id] = tail;
	  	nxt[a[i].id] = k + 1;
	  	nxt[tail] = a[i].id;
	  	tail = a[i].id;
  	}
  	
  	if (mn[head] != -1000000001)
    	chkmn(res, a[i].v - mn[head]);
    //printf("%d %d\n", *st.begin(), a[i].v);
  }
  printf("%d\n", res);
}

int main() {
  int _ = read<int>(); while (_--)
    sol();
  return 0;
}
