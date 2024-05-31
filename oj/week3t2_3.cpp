#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
const int Height = 19;
int n, T;
int fa[maxn], val[maxn], siz[maxn];
int getfa(int x)
{
	if (fa[x] == x) return x;
	return fa[x] = getfa(fa[x]);
}
struct node{
	node *ch[2] = {0};
};
node *rt[maxn];
void initial(node *x, int v, int h)
{
	if (h == -1) return;
	int nxt = v/(1 << h);
	x->ch[nxt] = new node();
	initial(x->ch[nxt], v % (1 << h), h - 1);
}
void merge(node *x, node *y, int h)
{
	if (h == -1) return;
	for (int i = 0; i < 2; i++)
	{
		if (y->ch[i] == NULL) 
			continue;
		else if (x->ch[i] == NULL)
			x->ch[i] = y->ch[i];
		else 
			merge(x->ch[i], y->ch[i], h - 1);
	}
}
int getans(node *x, int w, int h)
{
	if (h == -1) return 0;
	int best = (w / (1 << h)) ^ 1;
	if (x->ch[best] != NULL) 
		return (1 << h) + getans(x->ch[best], w % (1 << h), h - 1);
	else
		return getans(x->ch[best^1], w % (1 << h), h - 1);
}
int main()
{
	scanf("%d%d", &n, &T);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
		siz[i] = 1;
		scanf("%d", val + i);
		rt[i] = new node();
		initial(rt[i], val[i], Height);
	}
	for (int i = 1; i <= T; i++)
	{
		int op;
		scanf("%d", &op);
		if (op == 1)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			int fx = getfa(x), fy = getfa(y);
			if (fx != fy)
			{
				if (siz[fx] > siz[fy]) swap(fx, fy);
				siz[fy] += siz[fx];
				fa[fx] = fy;
				merge(rt[fy], rt[fx], Height);
			}
		}
		else
		{
			int x, w;
			scanf("%d%d", &x, &w);
			int fx = getfa(x);
			printf("%d\n", getans(rt[fx], w, Height));
		}
	}
	return 0;
}

