#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int n;
void sol()
{
	scanf("%d", &n);
	int s = 0;
	for (int i = 1; i < n; i++)
	{
		int x; 
		scanf("%d", &x);
		s += x;
	}
	printf("%d\n", -s);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)	sol();
	return 0;
}
