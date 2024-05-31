#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int f[maxn][maxn][maxn];
int main()
{
	f[0][0][0] = 1;
	int *cur = (int *)f[0];
	printf("%d\n", *cur);
	return 0;
}

