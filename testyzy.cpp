#include <iostream>
#include <cstdio>
#define N 500000
using namespace std;
long long count = 0;
struct fake_vector
{
    long long First;
    long long Second;
    long long order;
} list[N + 5];
fake_vector help[N + 5]; //��������
bool check(fake_vector a, fake_vector b) //�ж�a�ǲ��Ǳ�bС
{
    if (a.First < b.First || ((a.First == b.First) && (a.Second < b.Second)))
        return true;
    else
        return false;
}
fake_vector mymin(fake_vector a, fake_vector b)
{
    return check(a, b) ? a : b;
}
void merge(long long l, long long mid, long long r)
{
    long long i = 0;
    long long lIndex = l;
    long long rIndex = mid + 1;
    while (lIndex <= mid && rIndex <= r)
    {
        if (check(list[lIndex], list[rIndex]))
        {
            i++;
            help[i] = list[lIndex];
            lIndex++;
        }
        else
        {
            i++;
            count = count + mid - lIndex + 1;
            help[i] = list[rIndex];
            rIndex++;
        }
    }
    //��ߺ��ұ߿϶���һ�ߵ�ͷ�ˣ�������ͬʱ����Ϊÿ��ֻ�ƶ�һ��
    while (lIndex <= mid)
    {
        i++;
        help[i] = list[lIndex++];
    }
    while (rIndex <= r)
    {
        i++;
        help[i] = list[rIndex++];
    }
    for (long long j = 1; j <= r - l + 1; j++)
    {
        list[l + j - 1] = help[j];
    }
}
void mergeSort(long long l, long long r)
{
    if (l == r)
    {
        return;
    }
    long long mid = (l + r) / 2;
    //��벿�ֹ鲢����
    mergeSort(l, mid);
    //�Ұ벿�ֹ鲢����
    mergeSort(mid + 1, r);
    //���Ҳ��ֹ鲢
    merge(l, mid, r);
}
int main()
{
    long long n;
    scanf("%lld", &n);
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &list[i].First);
        scanf("%lld", &list[i].Second);
        list[i].order = i;
    }
    long long num = 0;
    long long i = 0;
    fake_vector min = list[1];
    while (i != n - 1)
    {
        i++;
        min = mymin(list[i], min);
        if (check(list[i + 1], min))
            num++;
    }
    mergeSort(1, n);
    long long ans = n - 1 + 2 * count - num;
    printf("%lld", ans);
    return 0;
}
