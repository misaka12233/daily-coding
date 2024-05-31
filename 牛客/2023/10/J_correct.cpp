#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

typedef pair<int,char> pic;

/* ---- read() & rlong() - begin ---- */
#define gc() (p0==p1&&(p1=(p0=buf)+fread(buf,1,1048576,stdin),p0==p1)?EOF:*p0++)
char buf[1048576],*p0,*p1;
inline int read() {
	int r=0; char c=gc(); while (c<48||c>57) c=gc();
	while (c>47&&c<58) {r=(r<<3)+(r<<1)+(c^48); c=gc();} return r;
}
inline char rchar() {char c=gc(); while (c<97||c>122) c=gc(); return c;}
#undef gc 
/* ---- read() & rlong() -- end ----- */

int cir,tag[1000005]; bool flg;
vector<int> acc,fat[1000005];
vector<char> ans[3];
vector<pic> stk,edg[1000005];

inline void sdfa(int u) {
	if (tag[u]&1) return;
	tag[u]|=1; for (auto i:edg[u]) sdfa(i.first);
}

inline void sbfa(int u) {
	if ((tag[u]&1)!=1||(tag[u]&2)) return;
	tag[u]|=2; for (auto i:fat[u]) sbfa(i);
}

inline void spfa(int u) {
	if (flg) return;
	if ((tag[u]&15)==7) {
		int v=0; flg=true; for (;stk.at(v).first!=u;++v);
		for (++v;stk.at(v).first!=u;++v) ans[1].emplace_back(stk.at(v).second);
		ans[1].emplace_back(stk.at(v).second); cir=stk.at(v).first; return;
	}
	else if ((tag[u]&3)!=3||(tag[u]&8)) return;
	tag[u]|=4;
	for (auto i:edg[u]) {
		stk.emplace_back(i);
		spfa(i.first);
		stk.pop_back();
	}
	tag[u]|=8;
}

inline void sqfa(int u,int v) {
	if (u==v) flg=true;
	if ((tag[u]&3)!=3||(tag[u]&16)||flg) return;
	tag[u]|=16; for (auto i:edg[u]) {
		ans[0].emplace_back(i.second);
		sqfa(i.first,v); if (flg) return; ans[0].pop_back();
	}
}

inline void sofa(int u) {
	if (tag[u]&64) flg=true;
	if ((tag[u]&3)!=3||(tag[u]&32)||flg) return;
	tag[u]|=32; for (auto i:edg[u]) {
		ans[2].emplace_back(i.second);
		sofa(i.first); if (flg) return; ans[2].pop_back();
	}
}

int main() {
	int m,q,u,v; read(); m=read(); q=read();
	acc.resize(q);
	for (int i=0;i<q;++i) tag[acc.at(i)=read()]=64;
	for (int i=0;i<m;++i) {
		u=read(); v=read();
		edg[u].emplace_back(make_pair(v,rchar()));
		fat[v].emplace_back(u);
	}
	sdfa(1); for (auto i:acc) sbfa(i);
	stk.emplace_back(make_pair(1,(char)0)); spfa(1);
	if (ans[1].empty()) {printf("-1"); return 0;}
	flg=false; sqfa(1,cir); flg=false; sofa(cir);
	for (auto i:ans[0]) putchar(i);
	for (auto i:ans[1]) putchar(i);
	for (auto i:ans[2]) putchar(i);
	return 0;
}
