#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	int sum = 0;
	for (int i = 1500; i >= 1; i--)
		for (int j = 1500; j >= i; j--)
			sum += j - i + 1;
	printf("%d\n", sum);
	return 0;
}

