#include <iostream>
#include <queue>
using namespace std;

class QueueToStackAdapter
{
    queue<int> mainQ;
    queue<int> helperQ;

public:
    QueueToStackAdapter()
    {
        mainQ = queue<int>();
        helperQ = queue<int>();
    }
    int size()
    {
        return mainQ.size();
    }

    void push(int val)
    {
        helperQ.push(val);
        while (mainQ.size()>0)
        {
            int x = mainQ.front();mainQ.pop();
            helperQ.push(x);
        }
        mainQ = helperQ;
        helperQ = queue<int>();
    }

    int pop()
    {
        if (mainQ.size() == 0)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        int x = mainQ.front();mainQ.pop();
        return x;
    }

    int top()
    {
        if (mainQ.size() == 0)
        {
            cout << "Stack underflow" << '\n';
            return -1;
        }
        int x = mainQ.front();
        return x;
    }
};

int main()
{
    QueueToStackAdapter stack;
    string str;
    cin >> str;
    while (str != "quit")
    {
        if (str == "pop")
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