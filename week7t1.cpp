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

int T;
char s[maxn];
int main()
{
    using namespace MyStack;

    stack st;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%s", s);
        int l = strlen(s);
        bool ans = true;
        st.init();
        for (int i = 0; i < l; i++)
        {
            if (s[i] == '(')
                st.push(1);
            else
            {
                if (st.pop() != 1)
                {
                    ans = false;
                    break;
                }
            }
        }
        if (st.getNum() != 0)
            ans = false;
        if (ans)
            puts("yes");
        else
            puts("no");
    }
    return 0;
}