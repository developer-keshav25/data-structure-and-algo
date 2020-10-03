#include<iostream>
using namespace std;
class HashMap<class K,class V>{
      private :
      class HMNode {
      K key;
      V value;

      HMNode(K key, V value) {
        this.key = key;
        this.value = value;
      }
    }

    private int size; // n
    private LinkedList<HMNode>[] buckets; 
}
int main(){
return 0;
}