#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int a[110]={0},b[110]={0},f[110][1010]={0};
int main()
{
	int n,i,j,v,x;
	cin>>v>>n;
	for(i=0;i<n;i++)
	cin>>a[i]>>b[i];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<=v;j++)
		{
			f[i][j]=f[i-1][j];
			if(j>=a[i-1]&&f[i-1][j-a[i-1]]+b[i-1]>f[i][j])
			f[i][j]=f[i-1][j-a[i-1]]+b[i-1];
		}
	}
	cout<<f[n][v]<<endl;
	return 0;
}
