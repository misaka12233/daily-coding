#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000 + 10;
typedef long long ll;
struct node{
    ll val;
    ll cnt;
};
node q[maxn];
int head = 1, tail = 0;
int Q;
int main()
{
    scanf("%d", &Q);
    for (int i = 1; i <= Q; i++)
    {
        int op;
        ll x, c;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%lld%lld", &x, &c);
            tail++;
            q[tail].val = x;
            q[tail].cnt = c;
        }
        else
        {
            scanf("%lld", &c);
            ll ans = 0;
            while (c)
            {
                if (q[head].cnt > c)
                {
                    ans += q[head].val * c;
                    q[head].cnt -= c;
                    c = 0;
                }
                else
                {
                    ans += q[head].val * q[head].cnt;
                    c -= q[head].cnt;
                    head++;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}