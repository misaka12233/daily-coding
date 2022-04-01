#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000 + 10;
int s[maxn];
int head[maxn], len[maxn];
int n, k;
bool warning;
bool check(int pos, int num) 
{
    if (pos < 0 || pos >= head[n - 1] + len[n - 1])
        return false;
    if (head[num] > pos || pos >= head[num] + len[num])
        warning = true;
    return true;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", len + i);
	for (int i = 0; i < n; i++)
	{
		if (i > 0)
			head[i] = head[i - 1] + len[i - 1];
		for(int j = 0; j < len[i]; j++)
			scanf("%d", s + head[i] + j);
	}
	scanf("%d", &k);
	while (k--)
	{
		int op;
		scanf("%d", &op);
		if (op == 0)
		{
			int x, y, v, c;
			scanf("%d%d%d%d", &x, &y, &v, &c);
			if (c == 0)
				puts("true");
			else
			{
				warning = false;
				if (check(head[x] + y, x) && check(head[x] + y + c - 1, x))
				{
					for (int i = 0; i < c; i++)
						s[head[x] + y + i] = v;
					if (warning) 
						printf("w");
					puts("true");
				}
				else
					puts("overflow");
			}
		}
		else if (op == 1)
		{
			int x0, x1, l, r, st;
			scanf("%d%d%d%d", &x0, &l, &x1, &st);
			bool legal = true;
			warning = false;
			l += head[x0];
			st += head[x1];
			if (check(l, x0))
			{
				for (int i = l; i <= head[n - 1] + len[n - 1]; i++)
				{
					if (s[i] == 0)
					{
						r = i;
						break;
					}
				}
				legal = legal && check(r, x0);
			}
			else
				legal = false;
			legal = legal && check(st, x1);
			legal = legal && check(st + r - l, x1);
			if (legal)
			{
				if (st + r - l < l || r < st)
				{
					for (int i = 0; i <= r - l; i++)
						s[st + i] = s[l + i];
					if (warning)
						printf("w");
					puts("true");
				}
				else
					puts("overwrite");
			}
			else
				puts("overflow");
		}
		else if (op == 2)
		{
			int x, l, r;
			scanf("%d%d", &x, &l);
			bool legal = true;
			warning = false;
			l += head[x];
			if (check(l, x))
			{
				for (int i = l; i <= head[n - 1] + len[n - 1]; i++)
				{
					if (s[i] == 0)
					{
						r = i;
						break;
					}
				}
				legal = legal && check(r, x);
			}
			else
				legal = false;
			if (legal)
			{
				if (warning)
					printf("w");
				printf("%d\n", r - l);
			}
			else
				puts("overflow");
		}
	}
	return 0;
}

