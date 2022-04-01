#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
struct node{
	int val;
	int cnt;
	node *lc, *rc;
};
void Insert(node *now, int val)
{
	if (val < now->val)
	{
		if (now->lc == NULL || now->lc->cnt == 0)
		{
			if (now->lc == NULL)
				now->lc = new node;
			now->lc->val = val;
			now->lc->cnt = 1;
			now->lc->lc = now->lc->rc = NULL;
		}
		else
			Insert(now->lc, val);
	}
	else if (val > now->val)
	{
		if (now->rc == NULL || now->rc->cnt == 0)
		{
			if (now->rc == NULL)
				now->rc = new node;
			now->rc->val = val;
			now->rc->cnt = 1;
			now->rc->lc = now->rc->rc = NULL;
		}
		else
			Insert(now->rc, val);
	}
	else if (val == now->val) now->cnt++;
}
node *getmin(node *now)
{
	if (now->lc == NULL || now->lc->cnt == 0)
		return now;
	else
		return getmin(now->lc);
}
void Remove(node *now)
{
	if (now->rc != NULL && now->rc->cnt != 0)
	{
		if (now->lc != NULL && now->lc->cnt != 0)
		{
			node *mn = getmin(now->rc);
			now->val = mn->val;
			now->cnt = mn->cnt;
			mn->val = mn->cnt = 0;
			Remove(mn);
		}
		else
		{
			now->val = now->rc->val;
			now->cnt = now->rc->cnt;
			now->lc = now->rc->lc;
			now->rc = now->rc->rc;
		}
	}
	else if (now->lc != NULL && now->lc->cnt != 0)
	{
		now->val = now->lc->val;
		now->cnt = now->lc->cnt;
		now->rc = now->lc->rc;
		now->lc = now->lc->lc;
	}
}
void Delete(node *now, int val)
{
	if (now == NULL || now->cnt == 0) return;
	if (val < now->val)
		Delete(now->lc, val);
	else if (val > now->val)
		Delete(now->rc, val);
	else if (val == now->val)
	{
		now->cnt--;
		if (now->cnt == 0)
		Remove(now);
	}
}
void Print(node *now)
{
	if (now == NULL || now->cnt == 0) return;
	printf("%d ", now->val);
	Print(now->lc);
	Print(now->rc);
}
node *rt;
int m;
int main()
{
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int op, x;
		scanf("%d", &op);
		if (op == 0)
			Print(rt), puts("");
		else if (op == 1)
		{
			scanf("%d", &x);
			if (rt == NULL || rt->cnt == 0)
			{
				rt = new node;
				rt->val = x;
				rt->cnt = 1;
				rt->lc = rt->rc = NULL;
			}
			else
				Insert(rt, x);
		}
		else if (op == 2)
			scanf("%d", &x), Delete(rt, x);
	}
	return 0;
}

