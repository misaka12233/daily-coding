#include<bits/stdc++.h>
using namespace std;
void sol()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	if (k == 1)
		puts("1");
	else if (k == 2)
		printf("%d\n", m / n + min(m, n - 1));
	else if (k == 3)
		printf("%d\n", m - m / n - min(m, n - 1));
	else
		puts("0");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--)	sol();
	return 0;
}

