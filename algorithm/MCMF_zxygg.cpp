#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX_N = 5005, MAX_M = 50005, MAX_2M = MAX_M<<1|5;
inline int rd(){
	int r=0;bool p=1;char c=getchar();
	while(c<'0' or c>'9'){ if(c=='-') p=0; c=getchar(); }
	while(c>='0' and c<='9') r=10*r+c-'0', c=getchar();
	return p?r:-r;
}
struct Edge {
    int v, c, w, nxt;
    Edge(int v=0, int c=0, int w=0, int nxt=0) : v(v), c(c), w(w), nxt(nxt) {}
} e[MAX_2M];
int head[MAX_N], cur[MAX_N], tot = 1;
int dis[MAX_N];
bool vis[MAX_N];
bool instk[MAX_N];
int n, m, S, T;
int pre[MAX_N];

void add_edge(int u, int v, int c, int w) {
    e[++tot] = Edge(v, c, +w, head[u]); head[u] = tot;
    e[++tot] = Edge(u, 0, -w, head[v]); head[v] = tot;
}

bool dijkstra() {
    memset(dis, 0x3f, sizeof(dis)); dis[S] = 0;
    memset(vis, 0, sizeof(vis));
    queue<int> pq; pq.push(S);
    vis[S] = true;
    while (!pq.empty()) {
        int u = pq.front(); pq.pop();
        vis[u] = false;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v, c = e[i].c, w = e[i].w;
            if (c and dis[v]>dis[u]+w) {
                dis[v] = dis[u]+w;
                pre[v] = i;
                if (!vis[v])
                {
                	pq.push(v);
                	vis[v] = true;
            	}
            }
        }
    }
    return (dis[T] != 0x3f3f3f3f);
}

int dfs(int u = S, int flow = 0x7fffffff) {
    if (u==T or !flow) return flow;
    instk[u] = 1;
    int rest = flow;
    for (int &i = cur[u]; i; i = e[i].nxt) {
        int v = e[i].v, c = e[i].c, w = e[i].w;
        if (c and !instk[v] and dis[v]==dis[u]+w) {
            int use = dfs(v, min(rest, c));
            if (!use) dis[v] = -1;
            else {
                e[i  ].c -= use;
                e[i^1].c += use;
                rest     -= use;
                if (!rest) { instk[u] = 0; return flow; }
            }
        }
    }
    instk[u] = 0;
    return flow-rest;
}

pii dinic() {
    int max_flow = 0, min_cost = 0;
    while (dijkstra()) {
        memcpy(cur, head, sizeof(head));
        int flow = dfs();
        max_flow += flow, min_cost += flow * dis[T];
    }
    return pii(max_flow, min_cost);
}

int augment() {
    int u, flow = 0x7fffffff;
    for (u = T; u != S; u = e[pre[u]^1].v) flow = min(flow, e[pre[u]].c);
    for (u = T; u != S; u = e[pre[u]^1].v) {
        e[pre[u]  ].c -= flow;
        e[pre[u]^1].c += flow;
    }
    return flow;
}

pii EK() {
    int max_flow = 0, min_cost = 0;
    while (dijkstra()) {
        int flow = augment();
        max_flow += flow, min_cost += flow * dis[T];
    }
    return pii(max_flow, min_cost);
}

int main() {
    n=rd(),m=rd(),S=rd(),T=rd();
    for (int i = 1; i <= m; ++i) {
        int u=rd(),v=rd(),c=rd(),w=rd();
        add_edge(u, v, c, w);
    }
    pii res = dinic();
    printf("%d %d\n", res.first, res.second);
    return 0;
}
