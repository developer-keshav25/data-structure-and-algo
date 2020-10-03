#include <iostream>
using namespace std;
class CustomQueue
{
    int *data;
    int front;
    int size;
    int cap;

public:
    CustomQueue(int cap)
    {
        data = new int[cap];
        front = 0;
        size = 0;
        this->cap = cap;
    }

    int Size()
    {
        return size;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            int idx = (front+i)%cap;
            cout << data[idx] << " ";
        }
        cout << '\n';
    }

    void add(int val)
    {
        if (size == cap)
        {
            cout << "Queue overflow" << '\n';
        }
        else
        {
            int rear = (front + size)%cap;
            data[rear] = val;
            ++size;
        }
    }

    int remove()
    {
        if (size == 0)
        {
            cout << "Queue underflow" << '\n';
            return -1;
        }
        int rem = data[front];
        front = (front+1)%cap;
        --size;
        return rem;
    }

    int peek()
    {
        if (size == 0)
        {
            cout << "Queue underflow" << '\n';
            return -1;
        }
        return data[front];
    }
};
int main()
{
    int n;cin>>n;
    CustomQueue queue(n);
    string input;
    cin>>input;
    while (input!="quit")
    {
        if(input=="add"){
            int x;cin>>x;
            queue.add(x);
        }
        else if(input=="peek"){
            int x =queue.peek();
            if(x!=-1)
            cout<<x<<'\n';
        }
        if(input=="remove"){
           int x =queue.remove();
            if(x!=-1)
            cout<<x<<'\n';
        }
        if(input=="size"){
            cout<<queue.Size()<<'\n';
        }
        if(input=="display"){
            queue.display();
        }
        cin>>input;
    }
    
    return 0;
}