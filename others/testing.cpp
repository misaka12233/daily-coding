#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n = 8;
int temperature[maxn] = {0,73,74,75,71,69,72,76,73};
int ans[maxn];
int my_stack[maxn], top;
int main()
{
	top = 0;
	my_stack[0] = 0;
	temperature[0] = inf;
	for (int i = n; i >= 1; i--)
	{
		while (top > 0 && temperature[i] >= temperature[my_stack[top]])
			top--;
		if (my_stack[top] != 0)
			ans[i] = my_stack[top] - i;
		my_stack[++top] = i;
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i]);
	return 0;
}

