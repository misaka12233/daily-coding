#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
struct node;
struct node{
	char color;
	int pos;
	node *nxt;
};
node *head;
int n;
node *getlink(int pos)
{
	node *now = head;
	while (now->nxt != NULL)
	{
		if (now->nxt->pos == pos)
			return now;
		now = now->nxt;
	}
	return now;
}
void Update(node *now)
{
	while (now->nxt != NULL)
	{
		now->nxt->pos = now->pos + 1;
		now = now->nxt;
	}
}
void Add(node *newnode)
{
	node *now = getlink(newnode->pos);
	newnode->nxt = now->nxt;
	now->nxt = newnode;
	Update(newnode);
}
void Delete(int pos)
{
	node *now = getlink(pos);
	now->nxt = now->nxt->nxt;
	Update(now);
}
void Switch(int x, int y)
{
	node *nodex = getlink(x), *nodey = getlink(y);
	char tmp;
	tmp = nodex->nxt->color;
	nodex->nxt->color = nodey->nxt->color;
	nodey->nxt->color = tmp;
	Update(nodex);
}
void Print()
{
	node *now = head;
	while (now->nxt != NULL)
	{
		printf("%c", now->nxt->color);
		now = now->nxt;
	}
	puts("");
}
int main()
{
	scanf("%d", &n);
	head = new node;
	head->pos = -1;
	head->nxt = NULL;
	for (int i = 1; i <= n; i++)
	{
		char op[3], color[3];
		int x, y;
		scanf("%s", op);
		if (op[0] == 'A')
		{
			scanf("%d%s", &x, color);
			node *now = new node;
			now->color = color[0];
			now->pos = x;
			Add(now);
		}
		else if (op[0] == 'D')
		{
			scanf("%d", &x);
			Delete(x);
		}
		else if (op[0] == 'S')
		{
			scanf("%d%d", &x, &y);
			Switch(min(x, y), max(x, y));
		}
		else
			Print();
	}
	return 0;
}

