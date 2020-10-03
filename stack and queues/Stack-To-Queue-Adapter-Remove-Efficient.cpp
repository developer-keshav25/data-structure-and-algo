#include <iostream>
#include <stack>
using namespace std;

class StackToQueueAdapter
{
    stack<int> mainS;
    stack<int> helperS;

public:
    StackToQueueAdapter()
    {
        mainS = stack<int>();
        helperS = stack<int>();
    }

    int size()
    {
        return mainS.size();
    }

    void add(int val)
    {
        while (mainS.size()>0)
        {
            int x  =mainS.top();mainS.pop();
            helperS.push(x);
        }
        mainS.push(val);
        while (helperS.size()>0)
        {
            int x  =helperS.top();helperS.pop();
            mainS.push(x);
        }
        
        
    }

    int remove()
    {
        if (mainS.size() == 0)
        {
            cout << "Queue underflow" << '\n';
            return -1;
        }
        int rem = mainS.top();mainS.pop();
        return rem;
        
    }

    int peek()
    {
        if (mainS.size() == 0)
        {
            cout << "Queue underflow" << '\n';
            return -1;
        }
        int rem = mainS.top();
        return rem;
    }
};

int main()
{
    StackToQueueAdapter queue;
    string input;
    cin >> input;
    while (input != "quit")
    {
        if (input == "add")
        {
            int x;
            cin >> x;
            queue.add(x);
        }
        else if (input == "peek")
        {
            int x = queue.peek();
            if (x != -1)
                cout << x << '\n';
        }
        if (input == "remove")
        {
            int x = queue.remove();
            if (x != -1)
                cout << x << '\n';
        }
        if (input == "size")
        {
            cout << queue.size() << '\n';
        }
        cin >> input;
    }

    return 0;
}