#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n;
int a[maxn];
bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	srand(time(0));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i] = 1;
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}

