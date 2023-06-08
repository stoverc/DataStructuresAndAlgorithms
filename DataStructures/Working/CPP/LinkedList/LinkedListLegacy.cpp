#include <iostream>
#include "Node.h"

//LinkedList.h
template <typename T>
class LinkedList {
    private:
        Node<T> head;
    public:
        LinkedList(T datum);
        LinkedList(Node<T> node);

        Node<T> GetHead();

        void Insert(T item, int ind);
        
};

template <typename T>
LinkedList<T>::LinkedList(T datum){
    head = Node<T>(datum);
}

template <typename T>
LinkedList<T>::LinkedList(Node<T> node){
    head = node;
}


template <typename T>
Node<T> LinkedList<T>::GetHead(){
    return head;
}

int main(){
    int x = 3;
    Node<int> node(x);

    std::cout << node.GetData() << " " << node.GetNext() << std::endl;

    LinkedList<int> ll(x);
    LinkedList<int> ll2(node);

    std::cout << ll.GetHead().GetData() << " " << ll.GetHead().GetNext() << std::endl;
    std::cout << ll2.GetHead().GetData() << " " << ll2.GetHead().GetNext() << std::endl;

    int test [] = {1,2,3,4,5};
    
    return 0;
}