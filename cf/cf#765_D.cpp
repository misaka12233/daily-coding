#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 300000 + 10;
int pow2[40];
struct node{
	int siz;
	int num;
	node *lc, *rc;
	node()
	{
		siz = num = 0;
		lc = rc = NULL;
	}
};
node *rt = new node();
void add(node *now, int dep, int val, int num)
{
	now->siz++;
	if (dep == -1)
	{
		now->num = num;
		return;
	}
	if (val < pow2[dep])
	{
		if (now->lc == NULL)
		now->lc = new node();
		add(now->lc, dep - 1, val, num);
	}
	else
	{
		if (now->rc == NULL)
		now->rc = new node();
		add(now->rc, dep - 1, val - pow2[dep], num);
	}
}
int n, k;
int ans[maxn], cnt;
bool findpair(node *nowx, node *nowy, int dep, int x, int y, bool pre)
{
	if (nowx == NULL || nowy == NULL)
		return false;
	if (dep == -1)
	{
		if ((x ^ y) >= k)
		{
			ans[++cnt] = nowx->num;
			ans[++cnt] = nowy->num;
			return true;
		}
		return false;
	}
	if (k & pow2[dep])
	{
		if (findpair(nowx->rc, nowy->lc, dep - 1, x + pow2[dep], y, pre))
			return true;
		if (findpair(nowx->lc, nowy->rc, dep - 1, x, y + pow2[dep], pre))
			return true;
		if (pre)
		{
			if (findpair(nowx->rc, nowy->rc, dep - 1, x + pow2[dep], y + pow2[dep], pre))
				return true;
			if (findpair(nowx->lc, nowy->lc, dep - 1, x, y, pre))
				return true;
		}
	}
	else
	{
		if (findpair(nowx->rc, nowy->lc, dep - 1, x + pow2[dep], y, true))
			return true;
		if (findpair(nowx->lc, nowy->rc, dep - 1, x, y + pow2[dep], true))
			return true;
		if (findpair(nowx->rc, nowy->rc, dep - 1, x + pow2[dep], y + pow2[dep], pre))
			return true;
		if (findpair(nowx->lc, nowy->lc, dep - 1, x, y, pre))
			return true;
	}
}
int getnum(node *now, int dep)
{
	if (dep == -1)
		return now->num;
	if (now->lc != NULL)
		return getnum(now->lc, dep - 1);
	else
		return getnum(now->rc, dep - 1);
}
void getcnt(node *now, int dep, int val)
{
	if (dep == -1)
	{
		ans[++cnt] = now->num;
		return;
	}
	if (k >= pow2[dep])
	{
		if(findpair(now, now, dep, val, val, false))
			return;
		ans[++cnt] = getnum(now, dep);
		return;
	}
	if (now->lc != NULL) getcnt(now->lc, dep - 1, val);
	if (now->rc != NULL) getcnt(now->rc, dep - 1, val + pow2[dep]);
}
int main()
{
	pow2[0] = 1;
	for (int i = 1; i <= 29; i++)
	pow2[i] = pow2[i - 1] << 1;
	scanf("%d%d", &n, &k);
	if (k == 0)
	{
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
			printf("%d ", i);
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		scanf("%d", &x);
		add(rt, 29, x, i);
	}
	getcnt(rt, 29, 0);
	if (cnt < 2)
	 	puts("-1");
	else
	{
		printf("%d\n", cnt);
		for (int i = 1; i <= cnt; i++)
		printf("%d ", ans[i]);
	}
	return 0;
}

