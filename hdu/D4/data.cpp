#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 10 + 10;
int main()
{
	srand(time(0));
	puts("3");
	for (int T = 1; T <= 3; T++)
	{
		puts("7 20");
		for (int i = 1; i <= 6; i++)
		{
			int x = rand() % 7 + 1;
			int y = rand() % 7 + 1;
			while (y == x) y = rand() % 7 + 1;
			printf("%d %d 0 %d\n", x, y, rand() % 20);
		}
		for (int i = 1; i <= 14; i++)
		{
			int x = rand() % 7 + 1;
			int y = rand() % 7 + 1;
			while (y == x) y = rand() % 7 + 1;
			printf("%d %d %d %d\n", x, y, rand() % 20, rand() % 20);
		}
	}
	return 0;
}

