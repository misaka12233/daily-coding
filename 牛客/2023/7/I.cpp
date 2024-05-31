#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 400 + 10;
const int mod = 998244353;
int n, ans;
ll p2[maxn];
char tmp[maxn];
char s[maxn][maxn];
vector<int> id[maxn];
struct node{
	int cnt = 0, ed = 0;
	node *lc = NULL;
	node *rc = NULL;
};
node rt;
int update_tmp(char *s)
{
	int lx = strlen(s);
	int cnt = 0;
	for (int i = 0; i < lx; i++)
	{
		if (s[i] == '0' && tmp[i] == '1') return -1;
		if (s[i] == '1' && tmp[i] == '0') return -1;
		if (s[i] != '?' && s[i] != tmp[i])
			tmp[i] = s[i];
		if (tmp[i] == '?') cnt++;
	}
	return cnt;
}
void insert_trie(node *now, char *s, int pos, int len)
{
	if (pos == len)
	{
		if (now->ed != 1)
		{
			now->ed = 1;
			now->cnt += 1;
		}
		return;
	}
	if (s[pos] == '0' || s[pos] == '?')
	{
		if (now->lc == NULL) now->lc = new node();
		insert_trie(now->lc, s, pos + 1, len);
	}
	if (s[pos] == '1' || s[pos] == '?')
	{
		if (now->rc == NULL) now->rc = new node();
		insert_trie(now->rc, s, pos + 1, len);
	}
	now->cnt = now->ed;
	if (now->lc != NULL) now->cnt += now->lc->cnt;
	if (now->rc != NULL) now->cnt += now->rc->cnt;
}
int main()
{
	int mxlen = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s[i]);
		int len = strlen(s[i]);
		mxlen = max(mxlen, len);
		id[len].push_back(i);
	}
	p2[0] = 1;
	for (int i = 1; i <= mxlen; i++)
		p2[i] = p2[i - 1] * 2 % mod;
	for (int len = 1; len <= mxlen; len++)
	{
		int lim = 24;
		if (len <= lim)
		{
			for (auto &i : id[len])
				insert_trie(&rt, s[i], 0, len);
		}
		else
		{
			int siz = id[len].size();
			int state = 1 << siz;
			for (int i = 1; i < state; i++)
			{
				for (int j = 0; j < len; j++)
					tmp[j] = '?';
				int res = len, cnt = 0;
				for (int j = 0; j < siz; j++)
				{
					if (i & (1 << j))
					{
						if (res != -1)
							res = update_tmp(s[id[len][j]]);
						cnt++;
					}
				}
				if (res != -1)
				{
					if (cnt & 1) ans = (ans + p2[res]) % mod;
					else ans = (ans - p2[res] + mod) % mod;
				}
			}
		}
	}
	ans = (ans + rt.cnt) % mod;
	printf("%d\n", ans);
	return 0;
}

