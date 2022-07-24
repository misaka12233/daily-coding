#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
template <typename type>
void read(type &a) 
{
    int t, f = 0;
    while (!isdigit(t = getchar())) 
        f |= t == '-';
    a = t - '0';
    while ( isdigit(t = getchar())) 
    {
        a *= 10;
        a += t - '0';
    }
    a = f ? -a : a;
}
const int maxn = 1000 + 10;

int n;
ll a[maxn];
ll ans[maxn][maxn];
struct node;
struct node{
    ll x;
    int rk;
    node* pre = NULL;
    node* nxt = NULL;
};
node* link[maxn];
struct List{
    ll x;
    int pos;
}b[maxn];
bool cmp(List p, List q)
{
    return p.x < q.x;
}
int main()
{
    read(n);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
        b[i].x = a[i];
        b[i].pos = i;
    }
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        int tail;
        for (int j = 1; j <= n; j++)
        {
            link[b[j].pos] = new node();
            link[b[j].pos]->x = b[j].x;
            link[b[j].pos]->rk = j;
            if (j != 1) 
            {
                link[b[j].pos]->pre = link[b[j - 1].pos];
                link[b[j - 1].pos]->nxt = link[b[j].pos];
            }
            if (b[j].pos >= i) tail = b[j].pos;
        }
        for (int j = 1; j < i; j++)
        {
            if (link[j]->pre != NULL) link[j]->pre->nxt = link[j]->nxt;
            if (link[j]->nxt != NULL) link[j]->nxt->pre = link[j]->pre;
            delete link[j];
        }
        node* nowMid;
        node* now = link[tail];
        ll cnt = 1;
        while (cnt < (n - i + 2) / 2)
        {
            now = now->pre;
            cnt++;
        }
        nowMid = now;
        for (int j = n; j >= i; j--)
        {
            if ((j - i + 1) & 1)
                ans[i][j] = nowMid->x * 2;
            else
                ans[i][j] = nowMid->x + nowMid->pre->x;
            if (link[j]->rk < nowMid->rk)
            {
                if ((j - i + 1) & 1)
                    nowMid = nowMid->nxt;
            }
            else if (link[j]->rk > nowMid->rk)
            {
                if ((j - i + 1) % 2 == 0)
                    nowMid = nowMid->pre;
            }
            else
            {
                if ((j - i + 1) & 1)
                    nowMid = nowMid->nxt;
                else
                    nowMid = nowMid->pre;
            }
            if (link[j]->pre != NULL) link[j]->pre->nxt = link[j]->nxt;
            if (link[j]->nxt != NULL) link[j]->nxt->pre = link[j]->pre;
            delete link[j];
        }
        //assert(sum == 0);
    }
    for (int l = 1; l <= n; l++)
        for (int i = 1; i + l - 1 <= n; i++)
            printf("%lld\n", ans[i][i + l - 1]);
    return 0;
}