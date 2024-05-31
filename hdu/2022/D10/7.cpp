#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int read()
{
    int ans=0,o=1;
    char c=getchar();
    for(;(c<'0'||c>'9')&&c!='-';c=getchar());
    if(c=='-') o*=-1,c=getchar();
    for(;'0'<=c&&c<='9';c=getchar())
        ans=ans*10+c-'0';
    return ans*o;
}
int T,n;
char s[10]; 
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		scanf("%s",s);
		if(s[0]=='A') 
		{
			if(n<=3) printf("%d\n",n/2);
			else
			{
				n++;
				int ans=0;
				ans+=3*(n/7);
				n%=7;
				if(n>=2) ans++;
				if(n>=5) ans++;
				printf("%d\n",ans);
			}
		}
		else 
		{
			if(n<=3) printf("%d\n",(n+1)/2);
			else
			{
				n-=3;
				int ans=2;
				ans+=3*(n/7);
				n%=7;
				if(n>=2) ans++;
				if(n>=5) ans++;
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
