#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100000 + 10;
int m;
//0 : www
//1 : iii
//2 : nnn
//3 : wwi
//4 : wwn
//5 : iiw
//6 : iin
//7 : nnw
//8 : nni
//9 : win
vector<int> state[10];
int out[10] = {1, 2, 3, 1, 1, 2, 2, 3, 3, 0};
int in[10] = {2, 3, 1, 3, 2, 3, 1, 2, 1, 0};
int nxt[10][4] = {{-1, 0, 3, 4}, {-1, 5, 1, 6}, {-1, 7, 8, 2}, 
				  {-1, 3, 5, 9}, {-1, 4, 9, 7}, {-1, 3, 5, 9},
				  {-1, 9, 6, 8}, {-1, 4, 9, 7}, {-1, 9, 6, 8}, {-1, -1, -1, -1}};
char ch[5] = "0win";
struct node{
	node(int x, int vx, int y, int vy): x(x), vx(vx), y(y), vy(vy) {}
	node() {}
	int x, vx;
	int y, vy;
};
vector<node> ans;
int getid(int x, int y, int z)
{
	if (x == 3) return 0;
	if (y == 3) return 1;
	if (z == 3) return 2;
	if (x == 2 && y == 1) return 3;
	if (x == 2 && z == 1) return 4;
	if (y == 2 && x == 1) return 5;
	if (y == 2 && z == 1) return 6;
	if (z == 2 && x == 1) return 7;
	if (z == 2 && y == 1) return 8;
	if (x == 1 && y == 1 && z == 1) return 9;
}
void sol()
{
	scanf("%d", &m);
	char s[5];
	ans.clear();
	for (int i = 0; i < 10; i++)
		state[i].clear(); 
	for (int i = 1; i <= m; i++)
	{
		int x = 0, y = 0, z = 0;
		scanf("%s", s);
		for (int j = 0; j < 3; j++)
		{
			if (s[j] == 'w')
			 	x++;
			if (s[j] == 'i')
			 	y++;
			if (s[j] == 'n')
			 	z++;
		}
		state[getid(x, y, z)].push_back(i);
	}
	while (state[9].size() != m)
	{
		int x = -1, y = -1;
		for (int i = 0; i < 9; i++)
		{
			if (state[i].size() != 0)
			{
				x = i;
				for (int j = 0; j < 9; j++)
				{
					if (state[j].size() != 0 && out[i] == in[j] && in[i] == out[j])
					{
						y = j;
						break;
					}
				}
				if (y != -1)
					break;
			}
		}
		if (y == -1)
		{
			for (int i = 0; i < 9; i++)
			{
				if (state[i].size() != 0)
				{
					x = i;
					for (int j = 0; j < 9; j++)
					{
						if (state[j].size() != 0 && out[i] == in[j])
						{
							y = j;
							break;
						}
					}
					if (y != -1)
						break;
				}
			}
		}
		int a = state[x][state[x].size() - 1], b = state[y][state[y].size() - 1];
		state[x].pop_back();
		state[nxt[x][out[y]]].push_back(a);
		state[y].pop_back();
		state[nxt[y][out[x]]].push_back(b);
		ans.push_back(node(a, out[x], b, out[y]));
	}
	printf("%d\n", ans.size());
	for (auto a : ans)
		printf("%d %c %d %c\n", a.x, ch[a.vx], a.y, ch[a.vy]);
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) sol();
	return 0;
}

