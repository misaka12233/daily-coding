#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 10;

namespace MyStack
{
    const int MaxSize = 200000;

    struct stack
    {
        int values[MaxSize];

        int top;

        void init()
        {
            memset(values, 0, sizeof(values));
            top = 0;
        }

        bool push(int x)
        {
            if (top == MaxSize)
                return false;
            values[top++] = x;
            return true;
        }

        int pop()
        {
            if (top == 0)
                return -inf;
            values[--top] = 0;
            return 1;
        }

        int getTop()
        {
            if (top == 0)
                return -inf;
            return values[top - 1];
        }

        int getNum()
        {
            return top;
        }
    };
}

int main()
{
    using namespace MyStack;

    stack st1, st2;
    int n;
    scanf("%d", &n);
    st1.init();
    st2.init();
    for (int i = 1; i <= n; i++)
    {
        int opt, x, t;
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            t = st1.getTop();
            if (t == -inf)
                puts("invalid option 1");
            else
            {
                st2.push(t);
                st1.pop();
            }
            break;
        case 2:
            t = st2.getTop();
            if (t == -inf)
                puts("invalid option 2");
            else
            {
                st1.push(t);
                st2.pop();
            }
            break;
        case 3:
            scanf("%d", &x);
            st1.push(x);
            break;
        case 4:
            t = st1.pop();
            if (t == -inf)
                puts("invalid option 4");
            break;
        case 5:
            t = st1.getTop();
            if (t == -inf)
                puts("invalid option 5");
            else
                printf("%d\n", t);
            break;
        default:
            printf("%d\n", st1.getNum());
            break;
        }
    }
    return 0;
}