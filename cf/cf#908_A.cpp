#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
char s[maxn];
void sol()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	printf("%c\n", s[n - 1]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

