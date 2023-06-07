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
            std::cout << p -> GetData() << "]";
        }

        p = p -> GetNext();
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    LinkedList<int> ll1(arr,5);

    ll1.Display();

    return 0;
}