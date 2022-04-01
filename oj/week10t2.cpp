#include<bits/stdc++.h>
using namespace std;
const int row = 22;
const int column = 80;
char s[2][row + 5][column];
int T;
int dirx[8]={1, 1, 1, 0, 0, -1, -1, -1};
int diry[8]={1, 0, -1, 1, -1, 1, 0, -1};
int getcnt(int x, int y, int lst)
{
	int ans = 0;
	for (int i = 0; i < 8; i++)
		if (s[lst][(x + dirx[i] + row) % row][(y + diry[i] + column) % column] == '*')
			ans++;
	return ans;
}
int main()
{
	scanf("%d", &T);
	for (int i = 0; i < 22; i++)
	{
		char c;
		c = getchar();
		for (int j = 0; j < 80; j++)
		s[0][i][j] = getchar();
	}
	int now = 1, lst = 0;
	while (T--)
	{
		for (int i = 0; i < 22; i++)
		{
			for (int j = 0; j < 80; j++)
			{
				int sum = getcnt(i, j, lst);
				s[now][i][j] = s[lst][i][j];
				if (s[lst][i][j] == '*' && (sum <= 1 || sum > 3))
					s[now][i][j] = ' ';
				else if (s[lst][i][j] == ' ' && sum == 3)
					s[now][i][j] = '*';
			}
		}
		swap(now, lst);
	}
	for (int i = 0; i < 22; i++)
	{
		for (int j = 0; j < 80; j++)
			putchar(s[lst][i][j]);
		printf("\n");
	}
	return 0;
}
