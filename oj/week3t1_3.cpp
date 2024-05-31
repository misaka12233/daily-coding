#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 50000;
const int maxl = 10000000 + 10;
struct node{
	vector<int> ed;
	int cnt = 0;
	map<int, node*> ch;
};
node *rt = new node();
int n;
char s[maxl];
int ans[maxn];
void trie_insert(node *x, int now, int id)
{
	x->cnt++;
	if (now == -1)
	{
		x->ed.push_back(id);
		return;
	}
	int nxt = s[now] - 'a';
	if (!x->ch.count(nxt))
		x->ch[nxt] = new node();
	trie_insert(x->ch[nxt], now - 1, id);
}
void trie_dfs(node *x)
{
	for (auto id : x->ed)
		ans[id] = x->cnt;
	for (auto nxt : x->ch)
		trie_dfs(nxt.second);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", s);
		trie_insert(rt, strlen(s) - 1, i);
	}
	trie_dfs(rt);
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
}

