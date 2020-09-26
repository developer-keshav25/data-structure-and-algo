#include <iostream>
#include <list>
using namespace std;
class LLToQueueAdapter
{
public:
    list<int> ll;
    int size();
    void add(int);
    int remove();
    int peek();
};
void LLToQueueAdapter::add(int val)
{
    ll.push_back(val);
}

int LLToQueueAdapter::remove()
{
    if (size() == 0)
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    int x = ll.front();
    ll.pop_front();
    return x;
}
int LLToQueueAdapter::size()
{
    return ll.size();
}
int LLToQueueAdapter::peek()
{
    if (size() == 0)
    {
        cout << "Queue underflow" << endl;
        return -1;
    }
    return ll.front();
}
int main()
{
    LLToQueueAdapter llstack;
    string input;
    while (input != "quit")
    {
        if (input == "add")
        {
            int val;
            cin >> val;
            llstack.add(val);
        }
        if (input == "remove")
        {
            int res = llstack.remove();
            if (res != -1)
                cout << res << endl;
        }
        if (input == "size")
            cout << llstack.size() << endl;
        if (input == "peek")
        {
            int res = llstack.peek();
            if (res != -1)
                cout << res << endl;
        }
        cin >> input;
    }

    return 0;
}