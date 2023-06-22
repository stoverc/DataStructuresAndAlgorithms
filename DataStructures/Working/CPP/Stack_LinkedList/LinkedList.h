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

        void Append(T datum);
        void InsertAtHead(T datum);
        void DeleteFromHead();
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
void LinkedList<T>::InsertAtHead(T datum){
    Node<T> *temp;

    temp = new Node<T>;
    temp -> SetData(datum);
    temp -> SetNext(head);
    head = temp;
}

template <typename T>
void LinkedList<T>::DeleteFromHead(){
    Node<T> *temp, *p;

    p = head;
    head = head -> GetNext();
    T x = p -> GetData();
    delete p;
}