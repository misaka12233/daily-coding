#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n;
int a[maxn];
int ch[maxn * 19][2];
int rt = 1, tot = 1;
void trie_ins(int now, int val, int h)
{
	if (h == -1) return;
	int c = (val >> h) & 1;
	if (ch[now][c] == 0)
		ch[now][c] = ++tot;
	trie_ins(ch[now][c], val, h - 1);
}
int trie_que(int now, int val, int h)
{
	if (h == -1) return 0;
	int c = (val >> h) & 1;
	if (ch[now][c ^ 1] == 0)
		return trie_que(ch[now][c], val, h - 1);
	else
		return trie_que(ch[now][c ^ 1], val, h - 1) + (1 << h);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
		scanf("%d", a + i);
	for (int i = n - 1; i >= 1; i--)
	{
		a[i] = a[i + 1] ^ a[i];
		trie_ins(rt, a[i], 19); 
	}
	int f;
	for (int i = 0; i < n; i++)
	{
		if (trie_que(rt, i, 19) < n)
		{
			f = i;
			break;
		}
	}
	for (int i = 1; i < n; i++)
		printf("%d ", f ^ a[i]);
	printf("%d\n", f);
	return 0;
}

