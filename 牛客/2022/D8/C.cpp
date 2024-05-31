#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100005;

int tag_sub[MAX_N], tag_add;
set<int> st[MAX_N];
int bel[MAX_N], col[MAX_N], mp[MAX_N];
int n, q, cnt;
int bl, br;
int sizC, sizB;
int indx;

void maintain_A() {
    if (cnt != sizC) return;
    for (int i = indx; i > br; --i) {
        for (auto &x: st[i]) bel[x] = 1;
        st[1].insert(st[i].begin(), st[i].end());
        st[i].clear();
    }
    sizC = cnt = 0;
}

void myswap(int x, int y){
	st[x].swap(st[y]);
	swap(tag_sub[x], tag_sub[y]);
	int a = mp[x], b = mp[y];
	swap(col[a], col[b]);
	mp[col[a]] = a;
	mp[col[b]] = b;
}

void sol() {
    scanf("%d%d", &n, &q);
    indx = 2, tag_add = cnt = 0;
    st[1].clear(), st[2].clear();
    col[1] = mp[1] = 1;
    col[2] = mp[2] = 2;
    for (int i = 1; i <= n; ++i) { st[2].insert(i); bel[i] = 2; }
    bl = 2, br = 2;
    sizC = 0;
    sizB = n;
    while (q--) {
        bool no_bug = 1;
        char opt[7]; scanf("%s", opt);
        if (opt[0] == 't') {
            int x, y; scanf("%d%d", &x, &y);
            if (y==0) {
                if (col[bel[x]]==1) no_bug = 0;
                else if (col[bel[x]] > br) {
                    st[col[bel[x]]].erase(x); st[2].insert(x); bel[x] = mp[2];
                    ++sizB;--sizC;
                    maintain_A();
                }
            } else {
                if (col[bel[x]]==1) {
                    st[1].erase(x); st[2].insert(x); bel[x] = mp[2];
                    ++sizB;
                }
                else if (col[bel[x]]<=br) no_bug = 0;
                else {
                    /*if (tag_add-tag_sub[bel[x]] > 0)*/ 
                    int cur = col[bel[x]];
                    ++tag_sub[cur]; --cnt;
                    st[cur].erase(x); st[2].insert(x); bel[x] = mp[2];
                    ++sizB;sizC--;
                    if (tag_add-tag_sub[cur] <= 0) {
                    	sizB += st[cur].size();
                    	sizC -= st[cur].size();
                        myswap(cur, br + 1);
                        br++;
                        tag_sub[br] = tag_add;
                    }
                    maintain_A();
                }
            }
        } else {
        	if (st[1].size() == n) no_bug = 0;
        	else
        	{
	            ++tag_add; ++cnt;
	            st[++indx].clear();
	            mp[indx] = col[indx] = indx;
	            myswap(2, indx);
	            tag_sub[2] = tag_add;
	            bl = br = 2;
	            sizC += sizB;
	            sizB = 0;
	            maintain_A();
	            // be
        	}
        }
        if (no_bug) printf("%d %d\n", st[1].size(), sizB);
        else puts("bug");
    }
}

int main() {
    srand(time(NULL));
    int _; scanf("%d", &_); while (_--) sol();
    return 0;
}
