#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
string s;
char ans[maxn];
int main()
{
	scanf("%d\n", &T);
	while (T--)
	{
		getline(cin, s);
		int l = s.length();
		int n = 0;
		bool inans = true;
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < l; i++)
		{
			if (inans) 
			{
				ans[n] = s[i] - 'a' + 'A';
				n++;
				inans = false;
			}
			if (s[i] == ' ') inans = true;
		}
		printf("%s\n", ans);
	}
	return 0;
}

