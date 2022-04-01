#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct node{
	node *nxt[30];
	bool isend;
	node()
	{
		for (int i = 0; i < 26; i++) nxt[i] = NULL;
		isend = false;
	}
};
node *rt;
void Insert(char* str)
{
	node *now = rt;
	for (int i = 0, l = strlen(str); i < l; i++)
	{
		if (now->nxt[str[i] - 'a'] == NULL) now->nxt[str[i] - 'a'] = new node();
		now = now->nxt[str[i] - 'a'];
	}
	now->isend = true;
}
bool Search(char* str)
{
	node *now = rt;
	for (int i = 0, l = strlen(str); i < l; i++)
	{
		if (now->nxt[str[i] - 'a'] == NULL) return false;
		now = now->nxt[str[i] - 'a'];
	}
	return now->isend;
}
int n;
char s[310];
int main()
{
	scanf("%d", &n);
	rt = new node();
	for (int i = 1; i <= n; i++)
	{
		char op[3];
		scanf("%s%s", op, s);
		if (op[0] == 'I') Insert(s);
		else if (Search(s)) puts("YES");
		else puts("NO");
	}
	return 0;
}

