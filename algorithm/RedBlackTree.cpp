#include<bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
namespace myRedBlackTree
{
	const int maxsize = 100000 + 10;
	struct Node
	{
		Node()
		{
			fa = ch[0] = ch[1] = NULL;
			col = 1;
			siz = cnt = 0;
		}
		Node(int v, Node *f);
		Node *ch[2];
        Node *fa;
		int val;
		int col;
		int siz;
		int cnt;
		
	};
	Node *nil = new Node;
	Node::Node(int v, Node *f)
	{
		fa = f;
		ch[0] = ch[1] = nil;
		val	= v;
		col = 0;
		siz = cnt = 1;
	}
	struct RBTree
	{
		int tot;
		Node *Rt;
		
		void initial()
		{
			tot = 0;
			Rt = nil;
			return;
		}
		
		void Rotate(Node *x, bool right)
        {
            Node *y = x->ch[!right];
            x->ch[!right] = y->ch[right];
            if (y->ch[right] != nil)
            	y->ch[right]->fa = x;
            y->fa = x->fa;
            if (x->fa == nil)
            	Rt = y;
            else
        		x->fa->ch[x == x->fa->ch[1]] = y;
        	y->ch[right] = x;
        	x->fa = y;
        	y->siz = x->siz;
        	x->siz = x->ch[0]->siz + x->ch[1]->siz + x->cnt;
        	return;
        }

		void Transplant(Node *to, Node *from)
		{
			from->fa = to->fa;
			if (to->fa == nil)
				Rt = from;
			else
				to->fa->ch[to == to->fa->ch[1]] = from;
		}
		
		Node* getMin(Node *x)
		{
			while (x->ch[0] != nil)
				x = x->ch[0];
			return x;
		}
		
		Node* getMax(Node *x)
		{
			while (x->ch[1] != nil)
				x = x->ch[1];
			return x;
		}
		
		Node* askNode(int val)
		{
			Node *x = Rt;
			while (x != nil)
			{
				if (x->val == val) 
					return x;
				x = x->ch[x->val < val];
			}
			return nil;
		}
		
        void doubleRedFix(Node *x)
        {
            while (x->fa != Rt && !x->fa->col)
            {
            	Node *fa = x->fa, *grand = fa->fa;
            	bool isLeft = fa == grand->ch[0];
            	Node *y = grand->ch[isLeft];
            	if (!y->col)
            	{
            		y->col = fa->col = 1;
            		grand->col = 0;
            		x = grand;
            	}
            	else
            	{
            		if (x == fa->ch[isLeft])
            		{
            			x = fa;
            			Rotate(x, !isLeft);
            		}
            		x->fa->col = 1;
            		x->fa->fa->col = 0;
            		Rotate(grand, isLeft);
            	}
            }
            Rt->col = 1;
            return;
        }
		
		void Insert(int val)
		{
			Node *x = Rt, *y = nil;
			while (x != nil)
			{
				y = x;
				y->siz++;
				if (x->val == val)
				{
					x->cnt++;
					return;
				}
				x = x->ch[x->val < val];
			}
			Node *z = new Node(val, y);
			if (y == nil)
				Rt = z;
			else
				y->ch[y->val < val] = z;
			doubleRedFix(z);
            return;
		}
		
		void doubleBlackFix(Node *x)
        {
        	while (x != Rt && x->col)
        	{
        		Node *fa = x->fa;
        		bool isLeft = x == fa->ch[0];
        		Node *y = fa->ch[isLeft];
        		if (!y->col)
        		{
        			fa->col = 0;
        			y->col = 1;
        			Rotate(fa, !isLeft);
        			y = fa->ch[isLeft];
        		}
        		if (!y->ch[0]->col || !y->ch[1]->col)
        		{
        			if (y->ch[isLeft]->col)
        			{
        				y->col = 0;
        				y->ch[!isLeft]->col = 1;
        				Rotate(y, isLeft);
        				y = fa->ch[isLeft];
        			}
        			y->col = fa->col;
        			fa->col = 1;
        			y->ch[isLeft]->col = 1;
        			Rotate(y->fa, !isLeft);
        			x = Rt;
        		}
        		else
        		{
        			y->col = 0;
        			x = x->fa;
        		}
        	}
        	x->col = 1;
            return;
        }

		void Delete(int val)
		{
            Node *z = Rt, *w = nil;
            while (z != nil)
            {
            	w = z;
            	w->siz--;
            	if (z->val == val)
            		break;
            	z = z->ch[z->val < val];
            }
            if (z != nil)
            {
            	if (z->cnt > 1)
            	{
            		z->cnt--;
            		return;
            	}
            	Node *y = z, *x;
            	int oldCol = y->col;
            	if (z->ch[0] == nil)
            	{
            		x = z->ch[1];
            		Transplant(z, z->ch[1]);
            	}
            	else if (z->ch[1] == nil)
            	{
            		x = z->ch[0];
            		Transplant(z, z->ch[0]);
            	}
            	else
            	{
            		y = getMin(z->ch[1]);
            		oldCol = y->col;
            		x = y->ch[1];
            		if (y->fa == z)
            			x->fa = y;
            		else
            		{
            			Node *tmp = y;
            			while (tmp != z)
            			{
            				tmp->siz -= y->cnt;
            				tmp = tmp->fa;
            			}
            			Transplant(y, y->ch[1]);
            			y->ch[1] = z->ch[1];
            			y->ch[1]->fa = y;
            		}
            		Transplant(z, y);
            		y->ch[0] = z->ch[0];
            		y->ch[0]->fa = y;
            		y->col = z->col;
            		y->siz = y->ch[0]->siz + y->ch[1]->siz + y->cnt;
				}
				if (oldCol)
					doubleBlackFix(x);
            }
            else
            {
            	while (w != nil)
            	{
            		w->siz++;
            		w = w->fa;
            	}
            }
			return;
		}
		
        int askRank(int val)
		{
			Node *x = Rt;
			int res = 1;
			while (x != nil)
			{
				if (x->val < val)
				{
					res += x->ch[0]->siz + x->cnt;
					x = x->ch[1];
				}
				else x = x->ch[0];
			}
            return res;
		}
			
		int askPrev(int val)
		{
			Insert(val);
			int res;
			Node *x = askNode(val);
			if (x->ch[0] != nil)
				res = getMax(x->ch[0])->val;
			else
			{
				while (x->fa->ch[0] == x)
					x = x->fa;
				if (x->fa == nil)
					res = inf;
				else
					res = x->fa->val;
			}
			Delete(val);
            return res;
		}
		
		int askNext(int val)
		{
			Insert(val);
			int res;
			Node *x = askNode(val);
			if (x->ch[1] != nil)
				res = getMin(x->ch[1])->val;
			else
			{
				while (x->fa->ch[1] == x)
					x = x->fa;
				if (x->fa == nil)
					res = inf;
				else
					res = x->fa->val;
			}
			Delete(val);
            return res;
		}
		
		int askValue(int rank)
		{
			Node *x = Rt;
			while (x != nil)
			{
				if (x->ch[0]->siz + 1 <= rank && rank <= x->ch[0]->siz + x->cnt)
					return x->val;
				if (x->ch[0]->siz + x->cnt < rank)
				{
					rank -= x->ch[0]->siz + x->cnt;
					x = x->ch[1];
				}
				else x = x->ch[0];
			}
			return inf;
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

