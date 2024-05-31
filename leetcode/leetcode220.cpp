#include<bits/stdc++.h>
using namespace std;
vector<int> nums = {1, 2, 3, 1};
int indexDiff = 3, valueDiff = 0;

const int maxn = 100000 + 10;
struct node{
    int val;
    int id;
    int l, r;
}a[maxn];
int n, tr[maxn];
int lowbit(int x)
{
    return x & -x;
}
int getsum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}
void add(int x, int v)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}
bool cmp(node x, node y)
{
    if (x.val == y.val) return x.id < y.id;
    return x.val < y.val;
}
bool containsNearbyAlmostDuplicate() {
    n = nums.size();
    for (int i = 1; i <= n; i++)
    {
        a[i].val = nums[i - 1];
        a[i].id = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int l = 1, r = n;
    for (int i = 1; i <= n; i++)
    {
        while (a[i].val - a[l].val > valueDiff && l < i) 
            l++;
        a[i].l = l;
    }
    for (int i = n; i >= 1; i--)
    {
        while (a[r].val - a[i].val > valueDiff && i < r) 
            r--;
        a[i].r = r;
    }
    l = 1, r = 0;
    for (int i = 1; i <= n; i++)
    {
        while (l < a[i].l)
        {
            add(a[l].id, -1);
            l++;
        }
        while (r < a[i].r)
        {
            r++;
            add(a[r].id, 1);
        }
        if (getsum(min(a[i].id + indexDiff, n)) - getsum(max(a[i].id - indexDiff, 1) - 1) > 1)
            return true;
    }
    return false;
}
int main()
{
	if (containsNearbyAlmostDuplicate()) puts("true");
	else puts("false");
}
