#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
void sol()
{
	int n;
	scanf("%d", &n);
	if (n % 3 == 0) puts("Second");
	else puts("First");
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

