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

        void Insert(T datum, int pos);
        void Delete(int pos);
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
    while(head){
        head = head -> GetNext();
        delete p;
        p = head;
    }
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
void LinkedList<T>::Insert(T datum, int pos){
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

        temp -> SetNext(p -> GetNext());
        T x = p -> GetData();
        delete p;
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

    ll1.Insert(10,0);
    ll1.Insert(15,3);
    ll1.Display();

    ll1.Delete(0);
    //std::cout << "The length is " << ll1.Length() << std::endl;
    ll1.Display();
    
    ll1.Delete(4);
    //std::cout << "The length is " << ll1.Length() << std::endl;
    ll1.Display();

    return 0;
}