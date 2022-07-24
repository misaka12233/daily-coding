#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	int k;
	scanf("%d", &k);
	printf("%d:", 21 + k / 60);
	if (k % 60 < 10)
		printf("0%d\n", k % 60);
	else
		printf("%d\n", k % 60);
	return 0;
}

