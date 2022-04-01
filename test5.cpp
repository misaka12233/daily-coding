#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
int f[100][2],a[100],ans; 
using namespace std;
int main()
{
	for(int i=1;i<=9;i++)
	scanf("%d",&a[i]);
	for(int i=1;i<=9;i++)
	{
		f[i][0]=f[i][1]=1;
		for(int j=1;j<i;j++)
		{
			if(a[i]>a[j]) f[i][0]=max(f[i][0],f[j][0]+1);
			if(a[i]<a[j]) f[i][1]=max(f[i][1],f[j][1]+1);
		}
		ans=max(ans,max(f[i][0],f[i][1]));
	}
	printf("%d\n",ans);
}

