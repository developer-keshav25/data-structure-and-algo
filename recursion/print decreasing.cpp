#include<iostream>
using namespace std;
void printDecreasing(int n){
    if(n<1)
    return;
    printDecreasing(n-1);
    cout<<n<<'\n';
}
int main(){
    int n;
    cin>>n;
    printDecreasing(n);
}
