#include<bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
namespace my_FHQTreap
{
	const int maxsize = 100000 + 10;
	
	struct Node
	{
		int lc, rc;
		int val;
		int pri;
		int siz;
	};
	struct FHQTreap
	{
		Node tr[maxsize];
	
		int tot, Rt;
		
		void initial()
		{
			tot = Rt = 0;
			return;
		}
		
		int newNode(int val)
		{
			tot++;
			tr[tot].lc = tr[tot].rc = 0;
			tr[tot].val	= val;
			tr[tot].pri = rand();
			tr[tot].siz = 1;
			return tot;
		}
		
		void pushup(int x)
		{
			tr[x].siz = tr[tr[x].lc].siz + tr[tr[x].rc].siz + 1;	
			return;	
		}
		
		void splitValue(int rt, int val, int &x, int &y)
		{
			if (!rt) 	
			{
				x = y = 0;
				return;
			}
			if (tr[rt].val <= val) 
				x = rt, splitValue(tr[rt].rc, val, tr[rt].rc, y);
			else
				y = rt, splitValue(tr[rt].lc, val, x, tr[rt].lc);
			pushup(rt);
			return;
		}
		
		void splitSize(int rt, int siz, int &x, int &y)
		{
			if (!rt) 
			{
				x = y = 0;
				return;
			}
			if (tr[tr[rt].lc].siz + 1 <= siz) 
				x = rt, splitSize(tr[rt].rc, siz - tr[tr[rt].lc].siz - 1, tr[rt].rc, y);
			else
				y = rt, splitSize(tr[rt].lc, siz, x, tr[rt].lc);
			pushup(rt);
			return;
		}
	
		int Merge(int x, int y)
		{
			if (!x || !y) 
				return x + y;
			if (tr[x].pri > tr[y].pri)
			{
				tr[x].rc = Merge(tr[x].rc, y);
				pushup(x);
				return x;
			}
			else
			{
				tr[y].lc = Merge(x, tr[y].lc);
				pushup(y);
				return y;
			}
		}
		
		void Insert(int val)
		{
			int x, y;
			splitValue(Rt, val - 1, x, y);
			Rt = Merge(Merge(x, newNode(val)), y);
			return;
		}
		
		void Delete(int val)
		{
			int x, y, z;
			splitValue(Rt, val - 1, x, y);
			splitValue(y, val, y, z);
			if (y)
				y = Merge(tr[y].lc, tr[y].rc);
			Rt = Merge(Merge(x, y), z);
		}
		
		int askRank(int val)
		{
			int x, y, ans;
			splitValue(Rt, val - 1, x, y);
			ans = tr[x].siz + 1;
			Rt = Merge(x, y);
			return ans;
		}
			
		int askValue(int rank)
		{
			int x, y, z, ans;
			splitSize(Rt, rank - 1, x, y);	
			splitSize(y, 1, y, z);
			ans = tr[y].val;
			Rt = Merge(Merge(x, y), z);
			return ans;
		}
		
		int askPrev(int val)
		{
			int x, y, now;
			splitValue(Rt, val - 1, x, y);
			now = x;
			while (tr[now].rc)
				now = tr[now].rc;
			Rt = Merge(x, y);
			return tr[now].val;
		}
		
		int askNext(int val)
		{
			int x, y, now;
			splitValue(Rt, val, x, y);
			now = y;
			while (tr[now].lc)
				now = tr[now].lc;	
			Rt = Merge(x, y);
			return tr[now].val;
		}
	};
}

//Õû¸ö¹Ö»î

int main()
{
	srand(time(0));
	using namespace my_FHQTreap;
	
	FHQTreap Tr;
	Tr.initial();
	int a, b;
	scanf("%d%d", &a, &b);
	Tr.Insert(a);
	Tr.Insert(b);
	printf("%d %d\n", Tr.askValue(1), Tr.askValue(2));
	/*scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		switch (op)
		{
			case 1:
				Tr.Insert(x);
				break;
			case 2:
				Tr.Delete(x);
				break;
			case 3:
				printf("%d\n", Tr.askRank(x));
				break;
			case 4:
				printf("%d\n", Tr.askValue(x));
				break;
			case 5:
				printf("%d\n", Tr.askPrev(x));
				break;
			default:
				printf("%d\n", Tr.askNext(x));
				break;
		}
	}*/
	return 0;
}

