#include <iostream>
#include <queue>
using namespace std;

class TwoStack
{
    int *data;
    int tos1;
    int tos2;
    int cap;

public:
    TwoStack(int cap)
    {
        data = new int[cap];
        tos1 = -1;
        tos2 = cap;
        this->cap = cap;
    }

    int size1()
    {
        return tos1 + 1;
    }

    int size2()
    {
        return cap - tos2;
    }

    void push1(int val)
    {
        if (tos2 - tos1 == 1)
        {
            cout << "Stack overflow" << '\n';
            return;
        }
        tos1++;
        data[tos1] = val;
    }

    void push2(int val)
    {
        if (tos2 - tos1 == 1)
        {
            cout << "Stack overflow" << '\n';
            return;
        }
        tos2--;
        data[tos2] = val;
    }

    int pop1()
    {
        if (tos1 == -1)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        int rem = data[tos1];
        tos1--;
        return rem;
    }

    int pop2()
    {
        if (tos2 == cap)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        int rem = data[tos2];
        tos2++;
        return rem;
    }

    int top1()
    {
        if (tos1 == -1)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        return data[tos1];
    }

    int top2()
    {
        if (tos2 == cap)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        return data[tos2];
    }
};

int main()
{
    int n;
    cin >> n;
    TwoStack stack(n);
    string str;
    cin >> str;
    while (str != "quit")
    {
        if (str == "pop1")
        {
            int x = stack.pop1();
            if (x != -1)
                cout << x << '\n';
        }
        else if (str == "pop2")
        {
            int x = stack.pop2();
            if (x != -1)
                cout << x << '\n';
        }
        else if (str == "top1")
        {
            int x = stack.top1();
            if (x != -1)
                cout << x << '\n';
        }
        else if (str == "top2")
        {
            int x = stack.top2();
            if (x != -1)
                cout << x << '\n';
        }
        else if (str == "size1")
            cout << stack.size1() << '\n';
        else if (str == "size2")
            cout << stack.size2() << '\n';
        else if (str == "push1")
        {
            int x;
            cin >> x;
            stack.push1(x);
        }
        else if (str == "push2")
        {
            int x;
            cin >> x;
            stack.push2(x);
        }
        cin >> str;
    }
    return 0;
}