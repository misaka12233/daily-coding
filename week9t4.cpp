#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500 + 10;
struct node;
struct node{
	int x, y;
	node *nxt[4];
}Pool[maxn * maxn];
node *now;
int n, t, nodesize;
int direction[2][4]={1, 0, 0, -1, 0, 1, -1, 0};
bool Erase;
void rush(int dir)
{
	if (now->nxt[dir] == NULL)
		return;
	if (Erase) 
	{
		for (int i = 0; i < 4; i++)
			if (now->nxt[i] != NULL)
				now->nxt[i]->nxt[3 - i] = now->nxt[3 - i];
		Erase = false;
	}
	now = now->nxt[dir];
	return;
}
int main()
{
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			nodesize++;
			Pool[nodesize].x = i;
			Pool[nodesize].y = j;
			for (int k = 0; k < 4; k++)
			{
				if (i + direction[0][k] < 1 || i + direction[0][k] > n || j + direction[1][k] < 1 || j + direction[1][k] > n)
					Pool[nodesize].nxt[k] = NULL;
				else
					Pool[nodesize].nxt[k] = &Pool[nodesize + direction[0][k] * n + direction[1][k]];
			}
		}
	}
	now = &Pool[1];
	char s[3];
	while (t--)
	{
		scanf("%s", s);
		switch (s[0])
		{
			case 'W': 
				rush(0);
				break;
			case 'D':
				rush(1);
				break;
			case 'A':
				rush(2);
				break;
			case 'S':
				rush(3);
				break;
			case 'B':
				Erase = true;
				break;
			default:
				printf("(%d, %d)\n", now->y, now->x);
		}
	}
	return 0;
}

