#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> allData;
    stack<int> minData;

public:
    int size()
    {
        return allData.size();
    }

    void push(int val)
    {
        allData.push(val);
        if (minData.size() == 0)
        {
            minData.push(val);
        }
        else if (val <= minData.top())
        {
            minData.push(val);
        }
    }

    int pop()
    {
        if (allData.size() == 0)
        {
            return -1;
        }
        int x = allData.top();
        allData.pop();
        if (x == minData.top())
            minData.pop();
        return x;
    }

    int top()
    {
        if (allData.size() == 0)
        {
            return -1;
        }
        int x = allData.top();
        return x;
    }

    int min()
    {
        if (minData.size() == 0)
        {
            return -1;
        }
        int x = minData.top();
        return x;
    }
};

int main()
{
    MinStack stack;
    string str;
    cin >> str;
    while (str != "quit")
    {
        if (str == "min")
        {
            int x = stack.min();
            if (x != -1)
                cout << x << '\n';
        }
        else if (str == "pop")
        {
            int x = stack.pop();
            if (x != -1)
                cout << x << '\n';
        }
        else if (str == "top")
        {
            int x = stack.top();
            if (x != -1)
                cout << x << '\n';
        }
        else if (str == "size")
            cout << stack.size() << '\n';
        else if (str == "push")
        {
            int x;
            cin >> x;
            stack.push(x);
        }
        cin >> str;
    }
    return 0;
}