#include<bits/stdc++.h>
#define N 100005
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
int n;
int a[N],p[N];
void sol(){
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read(),p[a[i]]=i;
	if(n==1){
		printf("%d %d\n",0,1);
		return;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		int x=p[i];
		swap(a[i],a[x]);
		sum^=x-i+1;
		p[a[i]]=i,p[a[x]]=x;
	}
	int k=1;
	while(k<=n)k<<=1;
	k-=3;
	printf("%d %d\n",sum&2,sum|k);
}
int main()
{
	int _=read();
	while(_--){
		sol();
	}
	return 0;
}
