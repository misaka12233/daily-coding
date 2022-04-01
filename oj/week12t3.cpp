#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
struct node{
	char op;
	int rank;
	bool binary;
};
node st_op[maxn];
int st_num[maxn], top_num, top_op;
char s[maxn];
int T;
bool Error;
void insertStack(int i)
{
	st_op[++top_op].op = s[i];
	if (s[i] == '(')
	st_op[top_op].rank = 6, st_op[top_op].binary = false;
	if (s[i] == ')')
		st_op[top_op].rank = 6, st_op[top_op].binary = true;
	if (s[i] == '+' || s[i] == '-' || s[i] == '~')
	{
		if (('0' <= s[i - 1] && s[i - 1] <= '9') || s[i - 1] == ')')
			st_op[top_op].rank = 4, st_op[top_op].binary = true;
		else
			st_op[top_op].rank = 2, st_op[top_op].binary = false;
	}
	if (s[i] == '*' || s[i] == '/' || s[i] == '%')
		st_op[top_op].rank = 3, st_op[top_op].binary = true;
	if (s[i] == '>' || s[i] == '<')
		st_op[top_op].rank = 5, st_op[top_op].binary = true;
}
bool calc()
{
	while (st_op[top_op].rank >= st_op[top_op - 1].rank && st_op[top_op].binary && top_op > 1)
	{
		if (st_op[top_op - 1].op == '(' && st_op[top_op].op == ')')
		{
			top_op -= 2;
			break;
		}
		int tmp;
		bool chk = true;
		if (st_op[top_op - 1].op == '+')
		{
			if(st_op[top_op - 1].binary)	
				tmp = st_num[top_num - 1] + st_num[top_num];
			else
				chk = false;		
		}
		if (st_op[top_op - 1].op == '-')
		{
			if(st_op[top_op - 1].binary)
				tmp = st_num[top_num - 1] - st_num[top_num];
			else
				st_num[top_num] = - st_num[top_num], chk = false;
		}
		if (st_op[top_op - 1].op == '~')
			st_num[top_num] = ~ st_num[top_num], chk = false;
		if (st_op[top_op - 1].op == '*')
			tmp = st_num[top_num - 1] * st_num[top_num];
		if (st_op[top_op - 1].op == '/')
		{
			if (st_num[top_num] == 0) 
				return true;
			tmp = st_num[top_num - 1] / st_num[top_num];
		}
		if (st_op[top_op - 1].op == '%')
		{
			if (st_num[top_num] == 0) 
				return true;
			tmp = st_num[top_num - 1] % st_num[top_num];
		}
		if (st_op[top_op - 1].op == '>')
			tmp = st_num[top_num - 1] > st_num[top_num];
		if (st_op[top_op - 1].op == '<')
			tmp = st_num[top_num - 1] < st_num[top_num];
		if (chk)
			st_num[--top_num] = tmp;
		st_op[top_op - 1] = st_op[top_op];
		top_op--;
	}
	return false;
}
int main()
{
	scanf("%d", &T);
	node init;
	init.op = '(';
	init.rank = 6;
	while (T--)
	{
		scanf("%s", s);
		int l = strlen(s);
		s[l] = ')';
		top_num = top_op = 0;
		st_op[++top_op] = init;
		Error = false;
		for (int i = 0; i <= l; i++)
		{
			if ('0' <= s[i] && s[i] <= '9')
				st_num[++top_num] = s[i] - '0';
			else
			{
				insertStack(i);
				Error = Error || calc();
				if (Error) 
					break;
			}
		}
		if (Error)
			puts("Runtime Error");
		else
			printf("%d\n", st_num[top_num]);
	}
	return 0;
}

