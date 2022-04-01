#include <bits/stdc++.h>
using namespace std;
const int MaxN = 505;
const int MaxC = 1003;
const int MaxM = 5e5 + 5;
const int PoolSize = MaxN * MaxC + MaxM;
struct ListItem;
typedef ListItem Li;

Li *head[MaxN], *tail[MaxN], *List[PoolSize];
int Index;

struct ListItem 
{
	int val;
	Li *nxt, *lst;
	int Listnum;
};

Li *GetNewListItem(int num) 
{
	List[++Index] = new ListItem;
	List[Index]->val = Index;
	List[Index]->nxt = List[Index]->lst = NULL;
	List[Index]->Listnum = num;
	return List[Index];
}
void print(Li *now)
{
	if(now == NULL)
		printf("NULL "); 
	else
		printf("%d ", now->val);
}
void Qry(int id)
{
	if (id > Index || id <= 0 || List[id] == NULL)
	{
		puts("NULL NULL NULL");
		return;
	}
	Li *now = List[id];
	print(now->lst);
	print(now);
	print(now->nxt);
	printf("\n");
}
void Erase(int id)
{
	if (id > Index || id <= 0)
		return;
	Li *now = List[id];
	if (now == NULL)
		return;
	if (now->nxt != NULL)
		now->nxt->lst = now->lst;
	if (now->lst != NULL)
		now->lst->nxt = now->nxt;
	if (head[now->Listnum] == now)
		head[now->Listnum] = now->nxt;
	if (tail[now->Listnum] == now)
		tail[now->Listnum] = now->lst;
	List[id] = NULL;
	return;
}
void inserthead(int nid)
{
	Li *now = GetNewListItem(nid);
	now->nxt = head[nid];
	if(head[nid] == NULL)
		tail[nid] = now;
	else
		head[nid]->lst = now;
	head[nid] = now;
	return;
}
void inserttail(int nid)
{
	Li *now = GetNewListItem(nid);
	now->lst = tail[nid];
	if(tail[nid] == NULL)
		head[nid] = now;
	else
		tail[nid]->nxt = now;
	tail[nid] = now;
	return;
}
void Update(int id, int x)
{
	if (id > Index || id <= 0)
		return;
	Li *now = List[id];
	if(now == NULL) 
		return;
	now->val = x;
	return;
}

int n, m;
int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int x;
		head[i] = tail[i] = NULL;
		scanf("%d", &x);
		for (int j = 1; j <= x; j++)
			inserttail(i);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		int op, id, x;
		scanf("%d%d", &op, &id);
		switch (op)
		{
			case 1: Qry(id); break;
			case 2: Erase(id); break;
			case 3: inserthead(id); break;
			case 4: inserttail(id); break;
			default: scanf("%d", &x); Update(id, x); break;
		}
	}
	return 0;
}

