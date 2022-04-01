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
		else
			ans = false, check(Rt, x);
	}
	return 0;
}

