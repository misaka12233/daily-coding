#include <cstdio>
#include <queue>
int n, m, r, h, e;
struct edge{
	int to, nxt, w;
}pic[80100];
int head[10100], cnt, vis[10100], used[40100];
struct node{
	int id, dis;
};
std::queue<node> q;
std::queue<int> iq;
void addedge(int u, int v, int i)
{
	pic[++cnt].to = v;
	pic[cnt].w = i;
	pic[cnt].nxt = head[u];
	head[u] = cnt;
}
void dfs(int u)
{
	vis[u] = 1;
	for(int i = head[u]; i; i = pic[i].nxt)
	{
		if(!vis[pic[i].to] && pic[i].w > 1)
			dfs(pic[i].to);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &r, &h);
	scanf("%d", &e);
	for(int i = 1; i <= e; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v, i);
		addedge(v, u, i);
	}
	vis[r] = 2;
	iq.push(r);
	while(iq.size())
	{
		int u = iq.front();
		iq.pop();
		for(int i = head[u]; i; i = pic[i].nxt)
		{
			if(!used[pic[i].w])
			{
				vis[pic[i].to]++;
				used[pic[i].w] = 1;
				if(vis[pic[i].to] == 2)
					iq.push(pic[i].to);
			}
		}
	}
	q.push((node){h, 0});
	vis[h] = -1;
	bool suc = 0;
	while(q.size())
	{
		node x = q.front();
		q.pop();
		for(int i = head[x.id]; i; i = pic[i].nxt)
		{
			int v = pic[i].to;	
			if(vis[v] > 1)
			{
				suc = 1;
				goto end;	
			}else if(vis[v] != -1 && x.dis + 1 < m)
			{
				vis[v] = -1;
				q.push((node){v, x.dis+1});
			}
		}
	}
	suc |= (h==r);
	end:
	printf("%swin\n", suc ? "hy" : "Rickk");
	return 0;
}
