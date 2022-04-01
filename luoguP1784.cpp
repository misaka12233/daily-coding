#include<bits/stdc++.h>
using namespace std;
int limit[800][350], ans_limit[800][3];
int ans[15][15];
bool row_vis[15][15], column_vis[15][15], block_vis[15][15];
struct node;
struct node{
	node *left, *right, *up, *down;
	int pos;
	int x, y, val;
};
int cnt;
node *head[350], *row_first[800], *row_tail[800], *column_tail[350];
int column_size[350];
node *newnode(int pos, int x, int y, int val)
{
	node *now = new node;
	now->pos = pos;
	now->x = x;
	now->y = y;
	now->val = val;
	now->left = now->right = now->up = now->down = NULL;
	return now;
}
void getlimit(int x, int y, int val)
{
	cnt++;
	limit[cnt][x * 9 + y + 1] = 1;
	limit[cnt][81 + x * 9 + val] = 1;
	limit[cnt][162 + y * 9 + val] = 1;
	limit[cnt][243 + ((x / 3) * 3 + y / 3) * 9 + val] = 1;
	ans_limit[cnt][0] = x;
	ans_limit[cnt][1] = y;
	ans_limit[cnt][2] = val;
}
void initial()
{
	cnt = 0;
	memset(limit, 0, sizeof(limit));
	memset(row_vis, 0, sizeof(row_vis));
	memset(row_tail, 0, sizeof(row_tail));
	memset(block_vis, 0, sizeof(block_vis));
	memset(column_vis, 0, sizeof(column_vis));
	memset(column_size, 0, sizeof(column_size));
	for (int i = 0; i < 9; i++)
	{
        for (int j = 0; j < 9; j++)
        {
		    scanf("%d", &ans[i][j]);
			row_vis[i][ans[i][j]] = column_vis[j][ans[i][j]] = block_vis[(i / 3) * 3 + j / 3][ans[i][j]] = true;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (ans[i][j])
				getlimit(i, j, ans[i][j]);
			else
			{
				for (int k = 1; k <= 9; k++)
				{
					if(!row_vis[i][k] && !column_vis[j][k] && !block_vis[(i / 3) * 3 + j / 3][k])
						getlimit(i, j, k);
				}
			}
		}
	}
	head[0] = newnode(0, -1, -1, -1);
	for (int i = 1; i <= 324; i++)
	{
		head[i] = newnode(i, -1, -1, -1);
		head[i]->left = head[i - 1];
		head[i - 1]->right = head[i];
		column_tail[i] = head[i];
	}
	head[0]->left = head[324];
	head[324]->right = head[0];
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= 324; j++)
		{
			if (limit[i][j])
			{
				node *now = newnode(j, ans_limit[i][0], ans_limit[i][1], ans_limit[i][2]);
				now->left = row_tail[i];
				if(row_tail[i] != NULL)
					row_tail[i]->right = now;
				else
					row_first[i] = now;
				now->up = column_tail[j];
				column_tail[j]->down = now;
				row_tail[i] = column_tail[j] = now;
				column_size[j]++;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		row_first[i]->left = row_tail[i];
		row_tail[i]->right = row_first[i];
	}
}
void deletecolumn(int pos)
{
	head[pos]->left->right = head[pos]->right;
	head[pos]->right->left = head[pos]->left;
	for (node *i = head[pos]->down; i != NULL; i = i->down)
	{
		for (node *j = i->right; j != i; j = j->right)
		{
			j->up->down = j->down;
			if(j->down != NULL)
				j->down->up = j->up;
			column_size[j->pos]--;
		}
	}
}
void deletelimit(node *t)
{
	ans[t->x][t->y] = t->val;
	for (node *now = t->right; now != t; now = now->right)
		deletecolumn(now->pos);
}
void recovercolumn(int pos)
{
	head[pos]->left->right = head[pos];
	head[pos]->right->left = head[pos];
	for (node *i = head[pos]->down; i != NULL; i = i->down)
	{
		for (node *j = i->right; j != i; j = j->right)
		{
			j->up->down = j;
			if(j->down != NULL)
				j->down->up = j;
			column_size[j->pos]++;
		}
	}
}
void recoverlimit(node *t)
{
	ans[t->x][t->y] = 0;
	for (node *now = t->right; now != t; now = now->right)
		recovercolumn(now->pos);
}
bool DLX()
{
	if (head[0]->right == head[0])
		return true;
	node *t;
	int mn = cnt;
	for (node *i = head[0]->right; i != head[0]; i = i->right)
	{
		if (column_size[i->pos] < mn)
			mn = column_size[i->pos], t = i;
	}
	if (!mn)
		return false;
	deletecolumn(t->pos);
	for (node *now = t->down; now != NULL; now = now->down)
	{
		deletelimit(now);
		if (DLX())
			return true;
		recoverlimit(now);
	}
	recovercolumn(t->pos);
	return false;
}
int T;
int main()
{
		initial();
		if (DLX())
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					printf("%d ", ans[i][j]);
				puts("");
			}
		}
	return 0;
}
