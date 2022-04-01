#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxl = 100 + 10;
const int maxn = 35 + 10;
char s[maxl], t[maxl];
int q, n, k;
int length[maxn];
char qry(int date, int rank)
{
	if (rank > length[date])
		return ' ';
	if(date == 1)
		return s[rank - 1];
	if(date == 2)
		return t[rank - 1];
	if (rank > length[date - 2])
		return qry(date - 1, rank - length[date - 2]);
	else
		return qry(date - 2, rank);
}
int main()
{
	scanf("%s%s%d", s, t, &q);
	length[1] = strlen(s);
	length[2] = strlen(t);
	for (int i = 3; i <= 35; i++)
		length[i] = length[i - 1] + length[i - 2];
	while (q--)
	{
		scanf("%d%d", &n, &k);
		for (int i = 0; i < 10; i++)
			printf("%c", qry(n, i + k));
		printf("\n");
	}
	return 0;
}

