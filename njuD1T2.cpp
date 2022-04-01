#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define maxn 100010
using namespace std;
int hd,n,tot;
struct node{
	int pre,nxt;
	int t;
};
node a[maxn];
void add(int x)
{
	int now=hd,nx;
	if(tot==n) return;
	tot++;
	a[tot].pre=tot;
	a[tot].nxt=hd;
	a[tot].t=x;
	a[hd].pre=tot;
	hd=tot;
	if(tot==n) return;
	while(a[now].nxt!=now)
	{
		tot++;
		nx=a[now].nxt;
		a[tot].pre=now;
		a[tot].nxt=nx;
		a[tot].t=x;
		a[nx].pre=tot;
		a[now].nxt=tot;
		now=nx;
		if(tot==n) return;
	}
	tot++;
	a[tot].pre=now;
	a[tot].nxt=tot;
	a[tot].t=x;
	a[now].nxt=tot;
}
int main()
{
	scanf("%d",&n);
	hd=1;
	tot++;
	a[tot].pre=a[tot].nxt=tot;
	a[tot].t=1;
	for(int i=2;i<=20;i++)
	{
		add(i);
		if(tot==n) break;
	}
	while(a[hd].nxt!=hd)
	printf("%d ",a[hd].t),hd=a[hd].nxt;
	printf("%d\n",a[hd].t);
}

