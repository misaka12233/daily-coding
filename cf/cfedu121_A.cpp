#include<bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 100 + 10;
int T;
char s[maxn]; 
int cnt[50];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%s", s);
		int l = strlen(s);
		memset(cnt, 0 , sizeof(cnt));
		for (int i = 0; i < l; i++)
		cnt[s[i]-'a']++;
		for (int i = 0; i < 26; i++)
		{
			for (int j = 1; j <= cnt[i]; j++)
			putchar(i + 'a');
		}
		puts("");
	}
	return 0;
}

