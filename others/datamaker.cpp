#include<bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int pre[maxn + 10], cnt = 0;
int main()
{
	srand(time(0));
	int T = maxn;
	printf("%d\n", T);
	for (int i = 1; i <= T; i++)
	{
		if (cnt == 0 || rand() & 1)
		{
			pre[++cnt] = rand();
			printf("I %d\n", pre[cnt]);
		}
		else
		{
			int k = rand() % cnt + 1;
			printf("D %d\n", pre[k]);
		}
	}
	return 0;
}

