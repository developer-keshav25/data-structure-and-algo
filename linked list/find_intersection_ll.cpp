#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <cmath>
using namespace std;
struct node
{
    int key;
    node *next;
    node(int key)
    {
        this->key = key;
        next = NULL;
    }
};
class linkedlist
{
public:
    node *head;
    node *tail;
    int size;
    linkedlist()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void addLast(int key)
    {
        if (this->size == 0)
        {
            this->head = this->tail = new node(key);
            this->size += 1;
        }
        else
        {
            this->tail->next = new node(key);
            this->tail = this->tail->next;
            this->size += 1;
        }
    }
    void display();
    int Size();
    void removeFirst();
    int getFirst();
    int getLast();
    int getAt(int);
    void addFirst(int);
    void addAt(int, int);
    void removeLast();
    void removeAt(int);
    void reverseDI();
    node *getnodeAt(int);
    void reversePI();
    int kthFromLast(int);
    int mid();
    void removeDuplicates();
    void oddEven();
    void kReverse(int);
    void displayReverse();
    void displayReverseHelper(node *);
    void reversePR();
    void reversePRHelper(node *);
    bool isPalindromeHelper(node *);
    bool isPalindrome();
    void Fold();
    void FoldHelper(node *, int);
    int addLinkedlistsHelper(node *, int, node *, int, linkedlist &);
    linkedlist addLinkedlists(linkedlist, linkedlist);
    int findIntersection(linkedlist, linkedlist);
};
void linkedlist::display()
{
    node *temp = this->head;
    while (temp != NULL)
    {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
}

int linkedlist::Size()
{
    return this->size;
}

void linkedlist::removeFirst()
{
    if (this->size == 0)
        cout << "List is empty" << endl;
    else if (this->size == 1)
    {
        this->head = this->tail = NULL;
        this->size -= 1;
    }
    else
    {
        this->head = this->head->next;
        this->size -= 1;
    }
}

int linkedlist::getFirst()
{
    if (this->size == 0)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    return this->head->key;
}
int linkedlist::getLast()
{
    if (this->size == 0)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    return this->tail->key;
}
int linkedlist::getAt(int idx)
{
    if (this->size == 0)
    {
        cout << "List is empty" << endl;
        return -1;
    }
    else if (idx >= this->size)
    {
        cout << "Invalid arguments" << endl;
        return -1;
    }
    else
    {
        node *temp = this->head;
        for (int i = 0; i < idx; i++)
        {
            temp = temp->next;
        }
        return temp->key;
    }
}
node *linkedlist::getnodeAt(int idx)
{
    node *temp = this->head;
    for (int i = 0; i < idx; i++)
    {
        temp = temp->next;
    }
    return temp;
}
void linkedlist::addFirst(int key)
{
    if (this->size == 0)
    {
        this->head = this->tail = new node(key);
        this->size += 1;
    }
    else
    {
        node *temp = new node(key);
        temp->next = this->head;
        this->head = temp;
        this->size += 1;
    }
}
void linkedlist::addAt(int key, int idx)
{
    if (idx < 0 || idx > this->size)
    {
        cout << "Invalid arguments" << endl;
    }
    else if (idx == 0)
    {
        addFirst(key);
    }
    else if (idx == this->size)
    {
        addLast(key);
    }
    else
    {
        node *ptr = this->head;
        for (int i = 0; i < idx - 1; i++)
        {
            ptr = ptr->next;
        }
        node *temp = new node(key);
        temp->next = ptr->next;
        ptr->next = temp;
        this->size += 1;
    }
}

void linkedlist::removeLast()
{
    if (this->size == 0)
        cout << "List is empty" << endl;
    else if (this->size == 1)
    {
        this->head = this->tail = NULL;
        size--;
    }
    else
    {
        node *head = this->head;
        for (int i = 0; i < size - 2; i++)
        {
            head = head->next;
        }
        tail = head;
        head->next = NULL;
        size--;
    }
}

void linkedlist::removeAt(int idx)
{
    if (idx < 0 || idx >= size)
        cout << "Invalid arguments" << endl;
    else if (idx == 0)
        removeFirst();
    else if (idx == size - 1)
        removeLast();
    else
    {
        node *pre;
        node *head = this->head;
        for (int i = 0; i < idx; i++)
        {
            pre = head;
            head = head->next;
        }
        pre->next = head->next;
        head->next = NULL;
        size--;
    }
}

void linkedlist::reverseDI()
{
    int i = 0, j = size - 1;
    while (i < j)
    {
        node *left = getnodeAt(i);
        node *right = getnodeAt(j);
        swap(left->key, right->key);
        i++;
        j--;
    }
}

void linkedlist::reversePI()
{
    node *prev = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        node *ocr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ocr;
    }
    node *temp = head;
    head = tail;
    tail = temp;
}

int linkedlist::kthFromLast(int k)
{
    node *prev = head;
    node *forw = head;
    for (int i = 0; i < k; i++)
    {
        forw = forw->next;
    }
    while (forw != tail)
    {
        prev = prev->next;
        forw = forw->next;
    }
    return prev->key;
}

int linkedlist::mid()
{
    node *s = head;
    node *f = head;
    while (f->next != NULL && f->next->next != NULL)
    {
        s = s->next;
        f = f->next->next;
    }
    return s->key;
}

linkedlist mergeTwoSortedLists(linkedlist l1, linkedlist l2)
{
    node *one = l1.head;
    node *two = l2.head;
    linkedlist res;
    while (one != NULL && two != NULL)
    {
        if (one->key < two->key)
        {
            res.addLast(one->key);
            one = one->next;
        }
        else
        {
            res.addLast(two->key);
            two = two->next;
        }
    }
    while (one != NULL)
    {
        res.addLast(one->key);
        one = one->next;
    }
    while (two != NULL)
    {
        res.addLast(two->key);
        two = two->next;
    }
    return res;
}
node *midNode(node *head, node *tail)
{
    node *f = head;
    node *s = head;
    while (f != tail && f->next != tail)
    {
        s = s->next;
        f = f->next->next;
    }
    return s;
}

linkedlist mergeSort(node *head, node *tail)
{
    if (head == tail)
    {
        linkedlist bs;
        bs.addLast(head->key);
        return bs;
    }
    node *mid = midNode(head, tail);
    linkedlist left = mergeSort(head, mid);
    linkedlist right = mergeSort(mid->next, tail);
    linkedlist cl = mergeTwoSortedLists(left, right);
    return cl;
}

void linkedlist::removeDuplicates()
{
    linkedlist res;
    while (size > 0)
    {
        int x = this->getFirst();
        this->removeFirst();
        if (res.size == 0 || x != res.tail->key)
        {
            res.addLast(x);
        }
    }
    this->head = res.head;
    this->tail = res.tail;
}

void linkedlist::oddEven()
{
    linkedlist odd;
    linkedlist even;
    while (size > 0)
    {
        int x = this->getFirst();
        this->removeFirst();
        if (x % 2 == 0)
            even.addLast(x);
        else
            odd.addLast(x);
    }
    if (odd.size > 0 && even.size > 0)
    {
        odd.tail->next = even.head;
        this->head = odd.head;
        this->tail = even.tail;
        this->size = odd.size + even.size;
    }
    else if (odd.size > 0)
    {
        this->head = odd.head;
        this->tail = odd.tail;
        this->size = odd.size;
    }
    else
    {
        this->head = even.head;
        this->tail = even.tail;
        this->size = even.size;
    }
}

void linkedlist::kReverse(int k)
{
    linkedlist prev;
    while (size > 0)
    {
        linkedlist curr;
        if (size >= k)
        {
            for (int i = 0; i < k; i++)
            {
                int val = this->getFirst();
                this->removeFirst();
                curr.addFirst(val);
            }
        }
        else
        {
            int s = size;
            for (int i = 0; i < s; i++)
            {
                int val = this->getFirst();
                this->removeFirst();
                curr.addLast(val);
            }
        }
        if (prev.head == NULL)
        {
            prev = curr;
        }
        else
        {
            prev.tail->next = curr.head;
            prev.tail = curr.tail;
            prev.size += curr.size;
        }
    }
    this->head = prev.head;
    this->tail = prev.tail;
    this->size = prev.size;
}
void linkedlist::displayReverseHelper(node *Node)
{
    if (Node == NULL)
        return;
    displayReverseHelper(Node->next);
    cout << Node->key << " ";
}
void linkedlist::displayReverse()
{
    displayReverseHelper(head);
    cout << endl;
}

void linkedlist::reversePRHelper(node *Node)
{
    if (Node == NULL)
        return;
    reversePRHelper(Node->next);
    if (Node == tail)
        return;
    else
    {
        Node->next->next = Node;
    }
}

void linkedlist::reversePR()
{
    reversePRHelper(head);
    head->next = NULL;
    node *temp = head;
    head = tail;
    tail = temp;
}

node *pleft;
bool linkedlist::isPalindromeHelper(node *right)
{
    if (right == NULL)
        return true;
    bool rres = isPalindromeHelper(right->next);
    if (rres == false)
        return false;
    else if (pleft->key != right->key)
        return false;
    else
    {
        pleft = pleft->next;
        return true;
    }
}

bool linkedlist::isPalindrome()
{
    pleft = head;
    return isPalindromeHelper(head);
}

void linkedlist::FoldHelper(node *right, int floor)
{
    if (right == NULL)
        return;
    FoldHelper(right->next, floor + 1);
    if (floor > size / 2)
    {
        node *temp = pleft->next;
        pleft->next = right;
        right->next = temp;
        pleft = temp;
    }
    else if (floor == size / 2)
    {
        tail = right;
        tail->next = NULL;
    }
}

void linkedlist::Fold()
{
    pleft = head;
    FoldHelper(head, 0);
}

int linkedlist::addLinkedlistsHelper(node *one, int pv1, node *two, int pv2, linkedlist &res)
{
    if (one == NULL && two == NULL)
        return 0;
    int data = 0;
    if (pv1 > pv2)
    {
        int oc = addLinkedlistsHelper(one->next, pv1 - 1, two, pv2, res);
        data = one->key + oc;
    }
    else if (pv1 < pv2)
    {
        int oc = addLinkedlistsHelper(one, pv1, two->next, pv2 - 1, res);
        data = two->key + oc;
    }
    else
    {
        int oc = addLinkedlistsHelper(one->next, pv1 - 1, two->next, pv2 - 1, res);
        data = one->key + two->key + oc;
    }
    int nd = data % 10;
    int nc = data / 10;
    res.addFirst(nd);
    return nc;
}

linkedlist linkedlist::addLinkedlists(linkedlist l1, linkedlist l2)
{
    linkedlist res;
    int oc = addLinkedlistsHelper(l1.head, l1.size, l2.head, l2.size, res);
    if (oc > 0)
        res.addFirst(oc);
    return res;
}

int linkedlist::findIntersection(linkedlist l1, linkedlist l2)
{

    node *t1 = l1.head;
    node *t2 = l2.head;
    int delta = std::abs(l1.size - l2.size);
    if (l1.size > l2.size)
    {
        for (int i = 0; i < delta; i++)
        {
            t1 = t1->next;
        }
    }
    else
    {
        for (int i = 0; i < delta; i++)
        {
            t2 = t2->next;
        }
    }
    while(t1!=t2){
        t1  =t1->next;
        t2 = t2->next;
    }
    return t1->key;
}

int main()
{
    linkedlist l1, l2;
    int n1, n2, x;
    cin >> n1;
    for (int i = 0; i < n1; i++)
    {
        cin >> x;
        l1.addLast(x);
    }
    cin >> n2;
    for (int i = 0; i < n2; i++)
    {
        cin >> x;
        l2.addLast(x);
    }

    int li, di;
    cin >> li >> di;
    if(li == 1){
      node* n = l1.getnodeAt(di);
      l2.tail->next = n;
      l2.tail = l1.tail;
      l2.size += l1.size - di;
    } else {
      node* n = l2.getnodeAt(di);
      l1.tail->next = n;
      l1.tail = l2.tail;
      l1.size += l2.size - di;
    }
    int inter = l1.findIntersection(l1,l2);
    cout<<inter;
    return 0;
}