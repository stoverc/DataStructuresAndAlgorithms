#include <iostream>
#include "LinkedList.h"

template <typename T>
class Stack {
    private:
        int size;
        LinkedList<T> data;
        int top;
    public:
        Stack();
        Stack(int n);

        ~Stack();

        void Display();
        void Push(T x);
        T Pop();
        T Peek(int index);
        bool IsEmpty();
        bool IsFull();
};

template <typename T>
Stack<T>::Stack(){
    size = 0;
    T arr[] = {};
    data = LinkedList<T>(arr,size);
    top = -1;
}

template <typename T>
Stack<T>::Stack(int n){
    size = n;
    T arr[] = {};
    data = LinkedList<T>(arr,size);
    top = -1;
}

template <typename T>
Stack<T>::~Stack(){
    top = -1;
}

template <typename T>
void Stack<T>::Display(){
    Node<T> *p = data.GetHead();
    int i = 0;

    std::cout << "[";

    while(p && i <= top){
        if(p -> GetNext() && i < top){
            std::cout << p -> GetData() << ",";
        }
        else{
            std::cout << p -> GetData() << "]" << std::endl;
        }

        i++;
        p = p -> GetNext();
    }
}

template <typename T>
void Stack<T>::Push(T x){
    Node<T> *t = new Node<T>();

    if(this -> IsFull()){
        std::cout << "Stack overflow!" << std::endl;
    }
    else{
        data.InsertAtHead(x);
        top++;
    }
}

template <typename T>
T Stack<T>::Pop(){
    Node<T> *p;
    T x;

    if(this -> IsEmpty()){
        std::cout << "Stack underflow!" << std::endl;
        return (T) NULL;
    }
    else{
        p = data.GetHead();
        x = p -> GetData();
        data.DeleteFromHead();
        top--;
        return x;
    }
}

template <typename T>
T Stack<T>::Peek(int index){
    Node<T> *p = data.GetHead();
    
    for(int i = 0; p != NULL && i < index-1; i++){
        p = p -> GetNext();
    }

    if(p != NULL){
        return p -> GetData();
    }
    else{
        std::cout << "Invalid Position!" << std::endl;
        return (T) NULL;
    }
}

template <typename T>
bool Stack<T>::IsEmpty(){
    if(data.GetHead() == NULL){
        return true;
    }
    else return false;
}

template <typename T>
bool Stack<T>::IsFull(){
    Node<T> *t = new Node<T>();

    if(t == NULL){
        return true;
    }
    else return false;
}

int main(){
    Stack<int> ll1(5);
    ll1.Push(10);
    ll1.Push(20);
    ll1.Push(30);
    ll1.Push(40);

    ll1.Display();

    std::cout << "Popping: " << ll1.Pop() << std::endl;

    ll1.Display();

    std::cout << "Peeking: " << ll1.Peek(1) << std::endl;
    std::cout << "Peeking: " << ll1.Peek(2) << std::endl;
    std::cout << "Peeking: " << ll1.Peek(3) << std::endl;
    std::cout << "Peeking: " << ll1.Peek(4) << std::endl;
    std::cout << "Peeking: " << ll1.Peek(5) << std::endl;
    ll1.Display();

    return 0;
}