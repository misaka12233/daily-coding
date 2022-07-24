#include<bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
namespace myRedBlackTree
{
	const int maxsize = 100000 + 10;
	
	struct Node
	{
		short int lc, rc;
        short int fa;
		int val;
		short int col;
		short int siz;
	};
	struct RBTree
	{
		Node tr[maxsize];
	
		int tot, Rt;
		
		void initial()
		{
			tot = Rt = 0;
            tr[0].col = 1;
			return;
		}
		
		int newNode(int val)
		{
			tot++;
			tr[tot].fa = tr[tot].lc = tr[tot].rc = 0;
			tr[tot].val	= val;
			tr[tot].col = 0;
			tr[tot].siz = 1;
			return tot;
		}
		
		void leftRotate(int x)
        {
            int y = tr[x].rc;
            if (x != Rt)
            {
                if (x == tr[tr[x].fa].lc)
                    tr[tr[x].fa].lc = y; 
                else 
                    tr[tr[x].fa].rc = y;
            }
            else Rt = y;
            tr[y].fa = tr[x].fa;
            tr[x].rc = tr[y].lc;
            tr[tr[x].rc].fa = x;
            tr[x].siz = tr[tr[x].lc].siz + tr[tr[x].rc].siz + 1;
            tr[y].lc = x;
            tr[x].fa = y;
            tr[y].siz = tr[tr[y].lc].siz + tr[tr[y].rc].siz + 1;
            return;
        }

        void rightRotate(int x)
        {
            int y = tr[x].lc;
            if (x != Rt)
            {
                if (x == tr[tr[x].fa].lc)
                    tr[tr[x].fa].lc = y; 
                else 
                    tr[tr[x].fa].rc = y;
            }
            else Rt = y;
            tr[y].fa = tr[x].fa;
            tr[x].lc = tr[y].rc;
            tr[tr[x].rc].fa = x;
            tr[x].siz = tr[tr[x].lc].siz + tr[tr[x].rc].siz + 1;
            tr[y].rc = x;
            tr[x].fa = y;
            tr[y].siz = tr[tr[y].lc].siz + tr[tr[y].rc].siz + 1;
            return;
        }

        void doubleRedFix(int x)
        {
            if (x == Rt)
            {
                tr[x].col = 1;
                return;
            }
            if (tr[tr[x].fa].col != 0) return;
            int dir1, dir2, uncle;
            if (tr[x].fa == tr[tr[tr[x].fa].fa].lc)
                dir1 = 0, uncle = tr[tr[tr[x].fa].fa].rc;
            else 
                dir1 = 1, uncle = tr[tr[tr[x].fa].fa].lc;
            if (tr[uncle].col == 0)
            {
                tr[uncle].col = tr[tr[x].fa].col = 1;
                tr[tr[tr[x].fa].fa].col = 0;
                doubleRedFix(tr[tr[x].fa].fa);
            }
            else
            {
                if (x == tr[tr[x].fa].lc)
                    dir2 = 0;
                else 
                    dir2 = 1;
                if (dir1)
                {
                    if (dir2 != dir1)
                    {
                        rightRotate(tr[x].fa);
                        leftRotate(x);
                        tr[x].col = 1;
                        tr[tr[x].lc].col = 0;
                    }
                    else
                    {
                        leftRotate(tr[x].fa);
                        tr[tr[x].fa].col = 1;
                        tr[tr[tr[x].fa].lc].col = 0;
                    }
                }
                else
                {
                    if (dir2 != dir1)
                    {
                        leftRotate(tr[x].fa);
                        rightRotate(x);
                        tr[x].col = 1;
                        tr[tr[x].rc].col = 0;
                    }
                    else
                    {
                        rightRotate(tr[x].fa);
                        tr[tr[x].fa].col = 1;
                        tr[tr[tr[x].fa].rc].col = 0;
                    }
                }
            }
            return;
        }
		
		void Insert(int val)
		{
			int x = newNode(val);
            if (Rt == 0)
            {
                Rt = x;
                tr[x].col = 1;
                return;
            }
            int now = Rt;
            while (now != 0)
            {
                tr[now].siz++;
                if (val <= tr[now].val)
                {
                    if (tr[now].lc == 0)
                    {
                        tr[now].lc = x;
                        tr[x].fa = now;
                        break;
                    }
                    else now = tr[now].lc;
                }
                else
                {
                    if (tr[now].rc == 0)
                    {
                        tr[now].rc = x;
                        tr[x].fa = now;
                        break;
                    }
                    else now = tr[now].rc;
                }
            }
            doubleRedFix(x);
            return;
		}
		
        int askRank(int val)
		{
			int now = Rt, res = 1;
            while (now != 0)
            {
                if (val <= tr[now].val)
                    now = tr[now].lc;
                else
                {
                    res += tr[tr[now].lc].siz + 1;
                    now = tr[now].rc;
                }
            }
            return res;
		}
			
		int askValue(int rank)
		{
			int now = Rt;
            while (now != 0)
            {
                if (rank == tr[tr[now].lc].siz + 1)
                    return tr[now].val;
                if (rank <= tr[tr[now].lc].siz)
                    now = tr[now].lc;
                else
                {
                    rank -= tr[tr[now].lc].siz + 1;
                    now = tr[now].rc;
                }
            }
            return 0;
		}
		
		int askPrev(int val)
		{
			int now = Rt, res = 0;
            while (now != 0)
            {
                if (val <= tr[now].val)
                    now = tr[now].lc;
                else
                {
                    res = tr[now].val;
                    now = tr[now].rc;
                }
            }
            return res;
		}
		
		int askNext(int val)
		{
			int now = Rt, res = 0;
            while (now != 0)
            {
                if (val < tr[now].val)
                {
                    res = tr[now].val;
                    now = tr[now].lc;
                }
                else
                    now = tr[now].rc;
            }
            return res;
		}

        void doubleBlackFix(int x)
        {
            if (tr[x].col <= 1 || x == Rt) return;
            int sibling;
            if (x == tr[tr[x].fa].lc)
            {
                sibling = tr[tr[x].fa].rc; 
                if (tr[sibling].col == 0)
                {
                    leftRotate(tr[x].fa);
                    tr[tr[x].fa].col = 0;
                    tr[tr[tr[x].fa].fa].col = 1;
                    doubleBlackFix(x);
                }
                else
                {
                    if (tr[tr[sibling].lc].col == 1 && tr[tr[sibling].rc].col == 1)
                    {
                        tr[x].col--;
                        tr[tr[x].fa].col++;
                        tr[sibling].col = 0;
                        doubleBlackFix(tr[x].fa);
                    }
                    else
                    {
                        if (tr[tr[sibling].rc].col != 0)
                        {
                            rightRotate(sibling);
                            tr[sibling].col = 0;
                            tr[tr[sibling].fa].col = 1;
                        }
                        sibling = tr[tr[x].fa].rc;
                        leftRotate(tr[x].fa);
                        tr[sibling].col = tr[tr[x].fa].col;
                        tr[tr[sibling].lc].col = tr[tr[sibling].rc].col = 1;
                        tr[x].col--;
                    }
                }
            }
            else 
            {
                sibling = tr[tr[x].fa].lc; 
                if (tr[sibling].col == 0)
                {
                    rightRotate(tr[x].fa);
                    tr[tr[x].fa].col = 0;
                    tr[tr[tr[x].fa].fa].col = 1;
                    doubleBlackFix(x);
                }
                else
                {
                    if (tr[tr[sibling].lc].col == 1 && tr[tr[sibling].rc].col == 1)
                    {
                        tr[x].col--;
                        tr[tr[x].fa].col++;
                        tr[sibling].col = 0;
                        doubleBlackFix(tr[x].fa);
                    }
                    else
                    {
                        if (tr[tr[sibling].lc].col != 0)
                        {
                            leftRotate(sibling);
                            tr[sibling].col = 0;
                            tr[tr[sibling].fa].col = 1;
                        }
                        sibling = tr[tr[x].fa].lc;
                        rightRotate(tr[x].fa);
                        tr[sibling].col = tr[tr[x].fa].col;
                        tr[tr[sibling].lc].col = tr[tr[sibling].rc].col = 1;
                        tr[x].col--;
                    }
                }
            }
        }

		void Delete(int val)
		{
            int now = Rt, originalCol;
            while (now != 0)
            {
                tr[now].siz--;
                if (val == tr[now].val) break;
                if (val < tr[now].val)
                    now = tr[now].lc;
                else
                    now = tr[now].rc;
            }
            int x, y;
            if (tr[now].lc == 0)
            {
                y = now;
                x = tr[now].rc;
            }
            else if (tr[now].rc == 0)
            {
                y = now;
                x = tr[now].lc;
            }
            else
            {
                y = tr[now].rc;
                while (tr[y].lc != 0) 
                {
                    tr[y].siz--;
                    y = tr[y].lc;
                }
                x = tr[y].rc;
            }
            if (y == tr[tr[y].fa].lc)
                tr[tr[y].fa].lc = x; 
            else 
                tr[tr[y].fa].rc = x;
            tr[x].fa = tr[y].fa;
            tr[x].col += tr[y].col;
            if (Rt == now && now == y) Rt = x;
            if (now != y)
                tr[now].val = tr[y].val;
            doubleBlackFix(x);
            tr[Rt].col = 1;
			return;
		}
	};
}

int n;
int main()
{
	using namespace myRedBlackTree;

	RBTree Tr;
	Tr.initial();
	scanf("%d", &n);
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
	}
	return 0;
}

