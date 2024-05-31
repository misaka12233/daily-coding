#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int randint(int k)
{
	int res = 0;
	for (int i = k; i >= 0; i--)
	{
		res <<= 1;
		if (rand() % 2)
			res += (1 << i);
	}
	return res;
}
int main()
{
	srand(time(0));
	printf("%d\n", randint(20));
	return 0;
}

