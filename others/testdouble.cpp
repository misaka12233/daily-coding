#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	int x = inf, y = inf - 1, z = -inf;
	double dx = x, dy = y, dz = z;
	printf("%d\n", dx*dy*dz == dz*dy*dx); 
	return 0;
}

