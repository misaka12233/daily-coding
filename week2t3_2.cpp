#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = 1000000 + 10;
struct node{
	int type;
	ll val;
	node *nxt[2];
}; 
node *head[2];
int n, m;
int type[maxn];
ll ans;
void Delete(node *now)
{
	if (now->nxt[0] != NULL)
	now->nxt[0]->nxt[1] = now->nxt[1];
	else 
	head[0] = now->nxt[1];
	if (now->nxt[1] != NULL)
	now->nxt[1]->nxt[0] = now->nxt[0];
	else
	head[1] = now->nxt[0];
}
void Union(node *now, int dir)
{
	ans = max(ans, now->val);
	now = now->nxt[dir];
	while (now != NULL && now->type == 2)
	{
		now->nxt[dir ^ 1]->val += now->val;
		ans = max(ans, now->nxt[dir ^ 1]->val);
		Delete(now);
		now = now->nxt[dir];
	}
}
void Insert(int type, ll val, int pos)
{
	node *now = new node();
	now->type = type;
	now->val = val;
	now->nxt[pos ^ 1] = head[pos];
	now->nxt[pos] = NULL;
	if (head[pos] == NULL)
		head[0] = head[1] = now;
	else
	{
		head[pos]->nxt[pos] = now;
		head[pos] = now;
	}
	if (type == 2)
		Union(now, pos ^ 1);
	else
	{
		int dir = type ^ 1;
		if (now->nxt[dir] != NULL)
		{
			if (now->nxt[dir]->type == dir)
			{
				now->val += now->nxt[dir]->val;
				now->type = 2;
				Delete(now->nxt[dir]);
				Union(now, dir);
			}
			else if (now->nxt[dir]->type == 2)
			{
				if (now->nxt[dir]->nxt[dir] != NULL && now->nxt[dir]->nxt[dir]->type == dir)
				{
					now->val += now->nxt[dir]->val;
					now->val += now->nxt[dir]->nxt[dir]->val;
					now->type = 2;
					Delete(now->nxt[dir]);
					Delete(now->nxt[dir]);
					Union(now, dir);
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", type + i);
	for (int i = 1; i <= n; i++)
	{
		ll val;
		scanf("%lld", &val);
		Insert(type[i], val, 1);
	}
	printf("%lld\n", ans);
	for (int i = 1; i <= m; i++)
	{
		int pos, typ;
		ll val;
		scanf("%d%d%lld", &pos, &typ, &val);
		Insert(typ, val, pos);
		printf("%lld\n", ans);
	}
	return 0;
}

