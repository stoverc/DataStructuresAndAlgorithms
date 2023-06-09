#include <iostream>
#include "Node.h"

//LinkedList.h
template <typename T>
class LinkedList {
    private:
        Node<T>* head;
    public:
        LinkedList();
        LinkedList(T arr[], int n);

        ~LinkedList();

        Node<T>* GetHead();

        void Display();
        int Length();
        T Sum();
        T Min();
        T Max();

        void Append(T datum);
        void Insert(int pos, T datum);
        void Delete(int pos);
        bool SortedQ();
        void DeleteDuplicates();
        void Reverse();
        LinkedList<T> Join (LinkedList<T> &list2);
        void Concatenate (LinkedList<T> &list2);
};

template <typename T>
LinkedList<T>::LinkedList(){
    head = NULL;
}

template <typename T>
LinkedList<T>::LinkedList(T arr[], int n){
    Node<T> *last, *temp;

    head = new Node<T>;
    head -> SetData(arr[0]);
    head -> SetNext(NULL);
    last = head;

    for(int i = 1; i < n; i++){
        temp = new Node<T>;
        temp -> SetData(arr[i]);
        temp -> SetNext(NULL);
        last -> SetNext(temp);
        last = temp;
    }
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T> *p = head;

    while(p){
        Node<T> *next = p -> GetNext();
        delete p;
        p = next;
    }
    
    head = NULL;
}

template <typename T>
Node<T>* LinkedList<T>::GetHead(){
    return head;
}

template <typename T>
void LinkedList<T>::Display(){
    Node<T> *p = head;

    std::cout << "[";

    while(p){
        if(p -> GetNext()){
            std::cout << p -> GetData() << ",";
        }
        else{
            std::cout << p -> GetData() << "]" << std::endl;
        }

        p = p -> GetNext();
    }
}

template <typename T>
int LinkedList<T>::Length(){
    Node<T> *p = head;
    int len = 0;

    while(p){
        len += 1;
        p = p -> GetNext();
    }

    return len;
}

template <typename T>
T LinkedList<T>::Sum(){
    Node<T> *p = head;
    int sum = 0;

    while(p){
        sum += p -> GetData();
        p = p -> GetNext();
    }

    return sum;
}

template <typename T>
T LinkedList<T>::Min(){
    Node<T> *p = head;
    T min = (T)INT_MAX;

    while(p){
        if(p -> GetData() < min){
            min = p -> GetData();
        }

        p = p -> GetNext();
    }

    return min;
}

template <typename T>
T LinkedList<T>::Max(){
    Node<T> *p = head;
    T max = (T)INT_MIN;

    while(p){
        if(p -> GetData() > max){
            max = p -> GetData();
        }

        p = p -> GetNext();
    }

    return max;
}

template <typename T>
void LinkedList<T>::Append(T datum){
    Node<T> *newnode = new Node<T>();
    newnode -> SetData(datum);
    newnode -> SetNext(NULL);

    if(head == NULL){
        head = newnode;
    }
    else{
        Node<T> *temp = head;
        while(temp -> GetNext()){
            temp = temp -> GetNext();
        }

        temp -> SetNext(newnode);
    }
}

template <typename T>
void LinkedList<T>::Insert(int pos, T datum){
    Node<T> *temp, *p;

    if(pos == 0){
        temp = new Node<T>;
        temp -> SetData(datum);
        temp -> SetNext(head);
        head = temp;
    }
    else if(pos > 0){
        p = head;

        for (int i = 0; i < pos-1; i++){
            p = p -> GetNext();
        }

        if(p){
            temp = new Node<T>;
            temp -> SetData(datum);
            temp -> SetNext(p -> GetNext());
            p -> SetNext(temp);
        }
    }
}

template <typename T>
void LinkedList<T>::Delete(int pos){
    Node<T> *temp, *p;

    if(pos == 0){
        p = head;
        head = head -> GetNext();
        T x = p -> GetData();
        delete p;
    }
    else if(pos > 0){
        p = head;
        temp = NULL;

        for (int i = 0; i < pos-1; i++){
            temp = p;
            p = p -> GetNext();
        }

        if(p){
            temp -> SetNext(p -> GetNext());
            T x = p -> GetData();
            delete p;
        }
    }
}

template <typename T>
bool LinkedList<T>::SortedQ(){
    T x = (T) INT_MIN;
    Node<T> *p = head;

    while(p){
        if(p -> GetData() < x){
            return false;
        }

        x = p -> GetData();
        p = p -> GetNext();
    }

    return true;
}

//====================
// Borrowed from 
// https://www.geeksforgeeks.org/remove-duplicates-from-an-unsorted-linked-list/
//====================
template <typename T>
void LinkedList<T>::DeleteDuplicates(){
    Node<T> *ptr1, *ptr2, *dup;

    ptr1 = head;

    while(ptr1 && ptr1 -> GetNext()){
        ptr2 = ptr1;

        while(ptr2 -> GetNext()){
            if(ptr1 -> GetData() == ptr2 -> GetNext() -> GetData()){
                dup = ptr2 -> GetNext();
                ptr2 -> SetNext(ptr2 -> GetNext() -> GetNext());
                delete dup;
            }
            else{
                ptr2 = ptr2 -> GetNext();
            }
        }

        ptr1 = ptr1 -> GetNext();
    }
}

template <typename T>
void LinkedList<T>::Reverse(){
    Node<T> *p, *q, *r;

    p = head;
    q = NULL;
    r = NULL;

    while(p){
        r = q;
        q = p;
        p = p -> GetNext();

        q -> SetNext(r);
    }

    head = q;
}

//====================
// Borrowed "third linked list" approach from
// https://stackoverflow.com/questions/68055899/concatenating-two-linked-lists-using-operator-overloading-c
//====================
template <typename T>
LinkedList<T> LinkedList<T>::Join(LinkedList<T> &list2){
    LinkedList<T> list3;

    Node<T> *ptr1 = head;
    Node<T> *ptr2 = list2.GetHead();

    while(ptr1){
        list3.Append(ptr1 -> GetData());
        ptr1 = ptr1 -> GetNext();
    }

    while(ptr2){
        list3.Append(ptr2 -> GetData());
        ptr2 = ptr2 -> GetNext();
    }

    return list3;
}

template <typename T>
void LinkedList<T>::Concatenate(LinkedList<T> &list2){
    Node<T> *ptr = list2.GetHead();

    while(ptr){
        this -> Append(ptr -> GetData());
        ptr = ptr -> GetNext();
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    LinkedList<int> ll1(arr,5);

    ll1.Display();
    std::cout << "The length is " << ll1.Length() << std::endl;
    std::cout << "The sum is " << ll1.Sum() << std::endl;
    std::cout << "The min is " << ll1.Min() << std::endl;
    std::cout << "The max is " << ll1.Max() << std::endl;
    std::cout << std::boolalpha << "ll1 is sorted? " << ll1.SortedQ() << std::endl;

    ll1.Insert(0,10);
    ll1.Insert(3,15);
    ll1.Display();

    ll1.Delete(0);
    //std::cout << "The length is " << ll1.Length() << std::endl;
    ll1.Display();
    
    ll1.Delete(4);
    //std::cout << "The length is " << ll1.Length() << std::endl;
    ll1.Display();

    LinkedList<int> ll2;
    ll2.Insert(0,8);
    ll2.Insert(1,3);
    ll2.Insert(2,6);
    ll2.Insert(0,5);
    ll2.Insert(3,9);
    ll2.Display();

    std::cout << std::boolalpha << "ll2 is sorted? " << ll2.SortedQ() << std::endl;

    ll2.Insert(0,8);
    ll2.Insert(1,3);
    ll2.Insert(2,6);
    ll2.Insert(2,6);
    ll2.Display();

    ll2.DeleteDuplicates();
    ll2.Display();

    ll2.Reverse();
    ll2.Display();

    ll2.Append(5);
    ll2.Append(6);
    ll2.Append(1349);
    ll2.Display();

    std::cout << "Concatenate: " << std::endl;
    ll1.Display();
    ll2.Display();
    LinkedList<int> ll3 = ll1.Join(ll2);
    ll3.Display();

    ll1.Concatenate(ll2);
    ll1.Display();

    return 0;
}