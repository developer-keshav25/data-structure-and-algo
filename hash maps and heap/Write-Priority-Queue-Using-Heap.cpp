#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class PriorityQeue
{
    vector<int> data;

private:
    void upheapify(int i)
    {
        if (i == 0)
            return;
        int pi = (i - 1) / 2; //parent index
        if (data.at(i) < data.at(pi))
        {
            swap(data[i], data[pi]);
            upheapify(pi);
        }
    }

void downheapify(int i){
    int min = i;
    int lc = 2*i+1;
    int rc = 2*i+2;
    if(lc<data.size()&&data[lc]<data[min]){
        min = lc;
    }
    if(rc<data.size()&&data[rc]<data[min]){
        min = rc;
    }
    if(min!=i){
        swap(data[i],data[min]);
        downheapify(min);
    }
}

public:
    PriorityQeue()
    {
        data = vector<int>();
    }
    void add(int val)
    {
        data.push_back(val);
        upheapify(data.size() - 1);
    }
    int remove()
    {
        if (data.size() == 0)
        {
            cout << "Underflow" << '\n';
            return -1;
        }
        swap(data[0], data[data.size()-1]);
        int rem = data[data.size()-1];
        data.pop_back();
        downheapify(0);
        return rem;
    }
    int peek()
    {
        if (data.size() == 0)
        {
            cout << "Underflow" << '\n';
            return -1;
        }
        return data[0];
    }

    int size()
    {
        return data.size();
    }
};
int main()
{
    PriorityQeue PQ;
    string input;
    cin >> input;
    while (input != "quit")
    {
        if (input == "add")
        {
            int x;
            cin >> x;
            PQ.add(x);
        }
        if (input == "peek")
        {
            int x = PQ.peek();
            if (x != -1)
                cout << x << '\n';
        }
        if (input == "remove")
        {
            int x = PQ.remove();
            if (x != -1)
                cout << x << '\n';
        }
        if (input == "size")
        {
            int x = PQ.size();
            cout << x << '\n';
        }
        cin >> input;
    }
    return 0;
}