#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
struct node;
struct node{
	int val;
	node *lc, *rc;
};
void Insert(node *&rt, int val)
{
	if (rt == NULL)
	{
		rt = new node;
		rt->val = val;
		rt->lc = rt->rc = NULL;
		return;
	}
	if (val == rt->val)
		return;
	if (val < rt->val)
		Insert(rt->lc, val);
	else
		Insert(rt->rc, val);
	return;
}
bool ans;
void check(node *rt, int val)
{
	if (rt == NULL)
	{
		puts("NO");
		return;
	}
	if (val == rt->val)
	{
		ans = true;
		puts("YES");
		printf("%d\n", rt->val);
		return;
	}
	if (val < rt->val)
		check(rt->lc, val);
	else
		check(rt->rc, val);
	if (ans)
		printf("%d\n", rt->val);
}
void Print(node *rt, int dep, bool islc)
{
	if (rt == NULL)
		return;
	Print(rt->lc, dep + 1, true);
	for (int i = 0; i < dep; i++)
		printf("  ");
	if (dep == 0)
		printf(":%d", rt->val);
	else if (islc)
		printf("/%d", rt->val);
	else
		printf("%c%d", 92, rt->val);
	puts("");
	Print(rt->rc, dep + 1, false);
}
int T;
node *Rt = NULL;
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		char c[3];
		int x;
		scanf("%s", c);
		scanf("%d", &x);
		if (c[0] == 'I')
			Insert(Rt, x);
		else if (c[0] == 'S')
			ans = false, check(Rt, x);
		else
			puts("====="), Print(Rt, 0, true), puts("=====");
	}
	return 0;
}

