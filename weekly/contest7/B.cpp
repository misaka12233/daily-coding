#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000 + 10;
int n, m;
char s[maxn], f[maxn];
void smallCase(char *a, int len)
{
	for (int i = 0; i < len; i++)
		if ('A' <= a[i] && a[i] <= 'Z')
			a[i] = a[i] - 'A' + 'a';
}
bool check()
{
	int i = 0, j = 0;
	while (i < n && j < m)
	{
		if (s[i] == f[j])
			i++, j++;
		else if (f[j] == 'a' || f[j] == 'e' || f[j] == 'i' || f[j] == 'o' || f[j] == 'u' || f[j] == 'y')
			j++;
		else
			return false;
	}
	while (j < m && (f[j] == 'a' || f[j] == 'e' || f[j] == 'i' || f[j] == 'o' || f[j] == 'u' || f[j] == 'y'))
		j++;
	return i == n && j == m;
}
int main()
{
	scanf("%s", s);
	n = strlen(s);
	scanf("%s", f);
	m = strlen(f);
	smallCase(s, n);
	smallCase(f, m);
	if (check())
		puts("Same");
	else
		puts("Different");
	return 0;
}

