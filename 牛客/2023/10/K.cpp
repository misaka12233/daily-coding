#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int n, m;
int main()
{
	scanf("%d%d", &n, &m);
	double p = 2.0 / n, res = 1.0;
	if (n >= 2)
	{
		for (int i = 1; i <= m; i++)
			res = res * p;
	}
	printf("%.15f\n", res); 
	return 0;
}

