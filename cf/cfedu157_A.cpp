#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
void sol()
{
	int x, y, k;
	scanf("%d%d%d", &x, &y, &k);
	if (x > y) printf("%d\n", x);
	else printf("%d\n", y + max(0, y - x - k));
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol(); 
	return 0;
}

