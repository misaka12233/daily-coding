#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 110
using namespace std;
int t,n;
int a[5][5];
char s[5]; 
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=3;i++)
		{
			scanf("%s",s);
			a[i][1]=s[0]-'0';
			a[i][2]=s[1]-'0';
			a[i][3]=s[2]-'0';
		}
		for(int i=1;i<=n;i++)
		{
			int o1,o2;
			scanf("%s",s);
			o1=(s[0]-'1')/2;
			o2=(s[0]-'1')%2;
			if(s[1]=='C')
			{
				int tmp=a[o1+1][o2+1];
				a[o1+1][o2+1]=a[o1+2][o2+1];
				a[o1+2][o2+1]=a[o1+2][o2+2];
				a[o1+2][o2+2]=a[o1+1][o2+2];
				a[o1+1][o2+2]=tmp;
			}
			else
			{
				int tmp=a[o1+1][o2+1];
				a[o1+1][o2+1]=a[o1+1][o2+2];
				a[o1+1][o2+2]=a[o1+2][o2+2];
				a[o1+2][o2+2]=a[o1+2][o2+1];
				a[o1+2][o2+1]=tmp;
			}
		}
		for(int i=1;i<=3;i++)
		{
			for(int j=1;j<=3;j++)
			printf("%d",a[i][j]);
			printf("\n");
		}
	}
}

