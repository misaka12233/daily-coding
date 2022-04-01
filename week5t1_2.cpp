#include <bits/stdc++.h>
using namespace std;
const int maxn = 20 + 5;

int n;
int ans;
void solve_down(int k);
void solve_up(int k);
void solve_down(int k)
{
    if (k == 0) return;
    if (k == 1)
    {
        printf("down 1\n");
        ans++;
        return;
    }
    solve_down(k - 2);
    printf("down %d\n", k);
    ans++;
    for (int i = k - 2; i >= 1; i--)
    {
        solve_up(i);
        printf("down %d\n", i + 1);
        ans++;
    }
    printf("down 1\n");
    ans++;
}
void solve_up(int k)
{
    if (k == 0) return;
    if (k == 1)
    {
        printf("up 1\n");
        ans++;
        return;
    }
    solve_up(k - 1);
    printf("up %d\n", k);
    ans++;
    for (int i = k - 2; i >= 1; i--)
    {
        solve_up(i);
        printf("down %d\n", i + 1);
        ans++;
    }
    printf("down 1\n");
    ans++;
}
int main()
{
    scanf("%d", &n);
    solve_down(n);
    printf("%d\n", ans);
    return 0;
}