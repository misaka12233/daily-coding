#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 22000010
using namespace std;
char a[maxn],s[maxn<<1];
int l[maxn<<1],n,ans; 
int main()
{
	scanf("%s",a);
	n=strlen(a);
	for(int i=1;i<=n;i++) 
	s[2*i]=a[i-1];
	n=n*2+1;
	for(int i=1;i<=n;i+=2) s[i]='#';
	l[1]=1;
	int k=1;
	ans=1;
	for(int i=2;i<=n;i++)
	{
		if(i+l[2*k-i]<k+l[k]) l[i]=l[2*k-i];
		else
		{
			int t=max(1,k+l[k]-i);
			while(i+t<=n&&s[i+t]==s[i-t]) t++;
			l[i]=t;
			k=i;
			ans=max(ans,l[i]);
		}
	}
	printf("%d\n",ans-1);
}

