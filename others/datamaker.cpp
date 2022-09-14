#include<bits/stdc++.h>
using namespace std;
int main()
{
	srand(time(0));
	int n = 1000;
	printf("%d\n", n);
	for (int i = 1; i <= n; i++)
	{
		int l = rand() % 100 + 1, r = rand() % 100 + 1;
		while (l == r) r = rand() % 100 + 1;
		if (l > r) swap(l, r);
		printf("%d %d\n", l, r);
	}
	return 0;
}

