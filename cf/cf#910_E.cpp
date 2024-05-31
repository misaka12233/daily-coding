#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 200000 + 10;
int n, m;
char s[maxn], t[maxn];
queue<int> pos[26];
bool sol()
{
	scanf("%d%d", &n, &m);
	scanf("%s", s);
	scanf("%s", t);
	for (int i = 0; i < 26; i++)
		while (!pos[i].empty())
			pos[i].pop();
	for (int i = 0; i < n; i++)
		pos[s[i] - 'a'].push(i);
	for (int i = 0; i < m; i++)
	{
		int id = t[i] - 'a';
		if (pos[id].empty()) return false;
		int p = pos[id].front();
		pos[id].pop();
		for (int j = 0; j < id; j++)
			while (!pos[j].empty() && pos[j].front() < p)
				pos[j].pop();
	}
	return true;
}
int main()
{
	int T;
	scanf("%d", &T);
	while (T--) 
	{
		if (sol()) puts("YES");
		else puts("NO");
	}
	return 0;
}

