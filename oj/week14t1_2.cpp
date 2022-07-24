#include <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
const ll maxlen = 20000 + 1;
int T;
struct node;
struct node{
    int x[8];
    node* nxt = NULL;
};
unordered_map<ll, node*> f;
ll Hash(node a)
{
    ll res = 0, now[7];
    for (int i = 1; i <= 6; i++)
    {
        ll p = max(a.x[i - 1], a.x[i + 1]), q = min(a.x[i - 1], a.x[i + 1]);
        now[i] = maxlen * q + p;
    }
    sort(now + 1, now + 7);
    for (int i = 1; i <= 6; i++)
        res = res * 131 + now[i];
    return res;
}
bool check(int *a, int *b)
{
    ll nowa[7];
    for (int i = 1; i <= 6; i++)
    {
        ll p = max(a[i - 1], a[i + 1]), q = min(a[i - 1], a[i + 1]);
        nowa[i] = maxlen * q + p;
    }
    sort(nowa + 1, nowa + 7);
    ll nowb[7];
    for (int i = 1; i <= 6; i++)
    {
        ll p = max(b[i - 1], b[i + 1]), q = min(b[i - 1], b[i + 1]);
        nowb[i] = maxlen * q + p;
    }
    sort(nowb + 1, nowb + 7);
    for (int i = 1; i <= 6; i++)
    {
        if (nowa[i] != nowb[i])
            return false;
    }
    return true;
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        char s[3];
        node a;
        scanf("%s", s);
        if (s[0] == 'I')
        {
            for (int i = 1; i <= 6; i++)
                scanf("%d", a.x + i);
            a.x[0] = a.x[6];
            a.x[7] = a.x[1];
            ll id = Hash(a);
            auto it = f.find(id);
            if (it != f.end())
            {
                node *now = f[id];
                while (now->nxt != NULL)
                {
                    if (check(now->x, a.x)) 
                        break;
                    now = now->nxt;
                }
                now->nxt = &a;
            }
            else f[id] = &a;
        }
        else
        {
            for (int i = 1; i <= 6; i++)
                scanf("%d", a.x + i);
            a.x[0] = a.x[6];
            a.x[7] = a.x[1];
            bool ans = false;
            ll id = Hash(a);
            auto it = f.find(id);
            if (it != f.end())
            {
                node *now = f[id];
                while (now->nxt != NULL)
                {
                    if (check(now->x, a.x))
                        break;
                    else 
                        now = now->nxt;
                }
                if (check(now->x, a.x)) ans = true;
            }
            if (ans) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}