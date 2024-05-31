#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 450;
int n, m;
struct node{
	ll val;
	node *nxt, *pre;
	node (ll val, node *pre)
	{
		this->val = val;
		this->pre = pre;
		nxt = NULL;
	}
};
node *head[maxn], *tail[maxn];
int siz[maxn];
int tot = 0;
ll tag[maxn] = {0}, sum[maxn] = {0};
int getpos(int x)
{
	int l = 1, r = tot, mid;
	while (l < r)
	{
		mid = l + r >> 1;
		if (siz[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}
void update(int num, int l, int r, int val)
{
	int cnt = 1;
	for (node *i = head[num]; i != NULL; i = i->nxt, cnt++)
	{
		if (l <= siz[num - 1] + cnt && siz[num - 1] + cnt <= r)
		{
			i->val += val;
			sum[num] += val;
		}
	}
}
void link(int num, int pos, node *newnode)
{
	if (pos == siz[num - 1] + 1)
	{
		newnode->nxt = head[num];
		head[num]->pre = newnode;
		head[num] = newnode;
	}
	else
	{
		int cnt = 1;
		for (node *i = head[num]; i != tail[num]; i = i->nxt, cnt++)
		{
			if (pos == siz[num - 1] + cnt + 1)
			{
				i->nxt->pre = newnode;
				newnode->nxt = i->nxt;
				i->nxt = newnode;
				newnode->pre = i;
			}
		}
	}
}
node* insert(int num, int pos, node *newnode)
{
	link(num, pos, newnode);
	sum[num] += newnode->val;
	if (siz[num] - siz[num - 1] == maxn)
	{
		sum[num] -= tail[num]->val;
		node *tmp = tail[num];
		tail[num] = tail[num]->pre;
		tail[num]->nxt = NULL;
		return tmp;
	}
	else
	{
		for (int i = num; i <= tot; i++)
			siz[i]++;
		return NULL;
	}
}
ll getres(int num, int l, int r)
{
	ll res = 0;
	int cnt = 1;
	for (node *i = head[num]; i != NULL; i = i->nxt, cnt++)
		if (l <= siz[num - 1] + cnt && siz[num - 1] + cnt <= r)
			res += i->val + tag[num];
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		ll v;
		scanf("%lld", &v);
		if (i % maxn == 0)
		{
			tot++;
			head[tot] = tail[tot] = new node(v, NULL);
			siz[tot] = siz[tot - 1] + 1;
			sum[tot] = v;
		}
		else
		{
			tail[tot]->nxt = new node(v, tail[tot]);
			tail[tot] = tail[tot]->nxt;
			siz[tot]++;
			sum[tot] += v;
		}
	}
	while (m--)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int l, r;
			ll c;
			scanf("%d%d%lld", &l, &r, &c);
			int lpos = getpos(l), rpos = getpos(r);
			update(lpos, l, r, c);
			if (lpos != rpos)
			{
				update(rpos, l, r, c);
				for (int i = lpos + 1; i <= rpos - 1; i++)
					tag[i] = tag[i] + c;
			}
		}
		else if (op == 2)
		{
			int l;
			ll c;
			scanf("%d%lld", &l, &c);
			int num = getpos(l);
			node *newnode = new node(c, NULL);
			for (int i = num, pos = l; i <= maxn && newnode != NULL; i++)
			{
				newnode->val -= tag[i];
				newnode->pre = newnode->nxt = NULL;
				if (i > tot)
				{
					tot++;
					head[tot] = tail[tot] = newnode;
					siz[tot] = siz[tot - 1] + 1;
					sum[tot] = newnode->val;
					newnode = NULL;
				}
				else
				{
					newnode = insert(i, pos, newnode);
					pos = siz[i] + 1;
				}
			}
		}
		else
		{
			int l, r;
			scanf("%d%d", &l, &r);
			int lpos = getpos(l), rpos = getpos(r);
			ll res = 0;
			res += getres(lpos, l, r);
			if (lpos != rpos)
			{
				res += getres(rpos, l, r);
				for (int i = lpos + 1; i <= rpos - 1; i++)
					res += sum[i] + tag[i] * (siz[i] - siz[i - 1]);
			}
			printf("%lld\n", res);
		}
	}
	return 0;
}

