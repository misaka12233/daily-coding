#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 500000 + 10;
char s[maxn];
int n, q;
int head;
int main()
{
	scanf("%d%d", &n, &q);
	scanf("%s", s);
	while (q--)
	{
		int op, x;
		scanf("%d%d", &op, &x);
		if (op == 1)
			head = (head - x + n) % n;
		else
			printf("%c\n", s[(head + x - 1) % n]);
	}
	return 0;
}

