#include<bits/stdc++.h>
using namespace std;

namespace my_FHQTreap
{
	const int maxsize = 100000 + 10;
	
	struct Node
	{
		int lc, rc;
		int pri;
		int siz;
		char color;
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
		
		int newNode(char color)
		{
			tot++;
			tr[tot].lc = tr[tot].rc = 0;
			tr[tot].pri = rand();
			tr[tot].siz = 1;
			tr[tot].color = color;
			return tot;
		}
		
		void pushup(int x)
		{
			tr[x].siz = tr[tr[x].lc].siz + tr[tr[x].rc].siz + 1;	
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
		
		void Insert(int rank, char color)
		{
			int x, y;
			splitSize(Rt, rank - 1, x, y);
			Rt = Merge(Merge(x, newNode(color)), y);
			return;
		}
		
		void Delete(int rank)
		{
			int x, y, z;
			splitSize(Rt, rank - 1, x, y);
			splitSize(y, 1, y, z);
			if (y)
				y = Merge(tr[y].lc, tr[y].rc);
			Rt = Merge(Merge(x, y), z);
		}
	
		char askColor(int rank)
		{
			int x, y, z;
			char ans;
			splitSize(Rt, rank - 1, x, y);	
			splitSize(y, 1, y, z);
			ans = tr[y].color;
			Rt = Merge(Merge(x, y), z);
			return ans;
		}
		
		void Switch(int rankx, int ranky)
		{
			if (rankx == ranky)
				return;
			int x, y, z, w, t;
			splitSize(Rt, rankx - 1, x, y);
			splitSize(y, 1, y, z);
			splitSize(z, ranky - rankx - 1, z, w);
			splitSize(w, 1, w, t);
			swap(tr[y].color, tr[w].color);
			Rt = Merge(Merge(Merge(Merge(x, y), z), w), t);
		}
		
		void Print(int rt)
		{
			if (!rt) 
				return;
			Print(tr[rt].lc);
			printf("%c", tr[rt].color);
			Print(tr[rt].rc);
		}
		
		void printans()
		{
			Print(Rt);
			printf("\n");
		}
	};
}

int n;
int main()
{
	srand(time(0));
	using namespace my_FHQTreap;
	FHQTreap Tr;
	Tr.initial();
	
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		char op[3], color[3];
		int x, y;
		scanf("%s", op);
		if (op[0] == 'A')
		{
			scanf("%d%s", &x, color);
			Tr.Insert(x + 1, color[0]);
		}
		else if (op[0] == 'D')
		{
			scanf("%d", &x);
			Tr.Delete(x + 1);
		}
		else if (op[0] == 'S')
		{
			scanf("%d%d", &x, &y);
			Tr.Switch(min(x + 1, y + 1), max(x + 1, y + 1));
		}
		else
			Tr.printans();
	}
	return 0;
}

