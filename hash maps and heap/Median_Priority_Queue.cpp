#include<iostream>
#include<queue>
using namespace std;
class medianPriorityQueue{
public:
priority_queue<int>left;
priority_queue<int, vector<int>, greater<int>>right;
void add(int val) {
    if(right.size()>0&&right.top()<val)
        right.push(val);
    else
        left.push(val);
    if(right.size()-left.size()==2){
        int x = right.top();
        right.pop();
        left.push(x);
      }
    else if(left.size()-right.size()==2){
          int x = left.top();
          left.pop();
          right.push(x);
      }
    }
int remove() {
    if(size()==0){
        cout<<"Underflow"<<'\n';
        return -1;
    }
    else if(left.size()>=right.size()){
      int x = left.top();
      left.pop();
      return x;
       }
      else
      {
      int x = right.top();
      right.pop();
      return x;
      }
    }

int peek() {
    if(size()==0){
        cout<<"Underflow"<<'\n';
        return -1;
    }

    else if(left.size()>=right.size())
    return left.top(); 
    else
    return right.top();
    }

int size() {
    return left.size()+right.size();
}
};
int main(){
    medianPriorityQueue qu;
    string str;
    cin>>str;
    while (str!= "quit") {
      if (str =="add") {
        int val;cin>>val;
        qu.add(val);
      } else if (str=="remove") {
        int val = qu.remove();
        if (val != -1) {
          cout<<val<<'\n';
        }
      } else if (str=="peek") {
        int val = qu.peek();
        if (val != -1) {
          cout<<val<<'\n';
        }
      } else if (str=="size") {
        cout<<qu.size()<<'\n';
      }
      cin>>str;;
    }
return 0;
}