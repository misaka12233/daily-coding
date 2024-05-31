#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int main(int argc, char *argv[])
{
	srand(time(0));
	puts("1");
	int n;
	sscanf(argv[1], "%d", &n);
	printf("%d\n", n);
	int cnt1 = n / 2, cnt0 = n / 2;
	for (int i = 1; i <= n; i++)
	{
		int x = rand() & 1;
		if (x == 1 && cnt1 > 0)
		{
			cnt1--;
			printf("%d", x);
		}
		else if (x == 0 && cnt0 > 0)
		{
			cnt0--;
			printf("%d", x);
		}
		else if (cnt1 == 0) printf("0");
		else if (cnt0 == 0) printf("1");
	}
	printf("\n"); 
	return 0;
}

