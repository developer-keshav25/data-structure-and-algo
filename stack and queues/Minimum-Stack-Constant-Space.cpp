#include <iostream>
#include <stack>
using namespace std;

class MinStack
{
    stack<int> allData;
    int min ;

public:
    MinStack(){
        this->min = 0;
    }
    int size()
    {
        return allData.size();
    }

    void push(int val)
    {
        if (allData.size() == 0)
        {
            allData.push(val);
            min = val;
        }
        else if(val>=min){
            allData.push(val);
            
        }
        else{
            allData.push(val+val-min);
            min = val;
        }
    }

    int pop()
    {
        if (allData.size() == 0)
        {
            cout<<"Stack underflow"<<'\n';
            return -1;
        }
        else{
        if(allData.top()>=min){
            int x = allData.top();allData.pop();
            return x;
        }
        else
        {
            int ov = min;
            min = 2*min - allData.top();allData.pop();
            return ov;
        }
        }
        
    }

    int top()
    {
        if (allData.size() == 0)
        {
            cout<<"Stack underflow"<<'\n';
            return -1;
        }
        if(allData.top()>=min){
            return allData.top();
        }
        else{
            return min;
        }
    }

    int Min()
    {
        if (allData.size()==0)
        {
            cout<<"Stack underflow"<<'\n';
            return -1;
        }
        
        return min;
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
            int x = stack.Min();
            if(x!=-1)
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