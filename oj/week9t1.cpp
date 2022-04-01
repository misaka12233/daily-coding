#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 1000000 + 10
using namespace std;
int t, top;
char s[maxn];
char sta[maxn];
bool ans;
int main()
{
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		int l = strlen(s);
		top = 0;
		ans = true;
		for (int i = 0; i < l; i++)
		{
			switch (s[i])
			{
				case ')': 
					if (sta[top] == '(')
						top--;
					else
						ans=false;
					break;
				case ']': 
					if (sta[top] == '[')
						top--;
					else
						ans=false;
					break;
				case '}': 
					if (sta[top] == '{')
						top--;
					else
						ans=false;
					break;
				default:
					sta[++top] = s[i];
					break;
			}
			if (!ans) 
				break;
		}
		if (ans && top == 0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}

