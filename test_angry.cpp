#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main()
{
	int x, y;
	cin >> x >> y;
	x = x + (y << 10);
	while (x)
	{
		cout << (x&1);
		x >>= 1;
	}
	return 0;
}

