#include <iostream>
#include <limits>           // allows NaN type
#include <cmath>            // allows std::isnan()
#include <vector>

namespace cs{
    template <typename T>
    bool isnan(T num){
        return num == T(std::nan("1"));
    }
}

template <typename T>
class node{
    public:
        T data;             // Find a way to make private?
        node<T>* next;      // Ditto?
        node<T>();
        node<T>(T datum);
};

template <typename T>
node<T>::node(){
    data = std::nan("1");
    next = NULL;
}

template <typename T>
node<T>::node(T datum){
    this->data = datum;
    this->next = NULL;
}

template <typename T>
class MyLinkedList{
    public:
        MyLinkedList<T>();
        void addAtHead(T val);
        void addAtTail(T val);

        void print();
    private:
        node<T>* head;
};

template <typename T>
MyLinkedList<T>::MyLinkedList(){
    head = NULL; 

    std::cout << "Creating an empty linked list...." << std::endl;
}

template <typename T>
void MyLinkedList<T>::addAtHead(T val){
    node<T>* new_node = new node(val);

    if(head == NULL){
        head = new_node;
    } else{
        (*new_node).next = head;
        head = new_node;
    }

    std::cout << "The new head is " << (*head).data << std::endl;
}

template <typename T>
void MyLinkedList<T>::print(){
    if(head==NULL){
        std::cout << "[]" << std::endl;
    } else {
        std::vector<T> tempvec;
        node<T>* curr = head;

        while(curr != NULL){
            tempvec.push_back((*curr).data);
            curr = (*curr).next;
        }

        std::cout << "[";

        for(int i = 0; i < tempvec.size(); i++){
            std::cout << tempvec.at(i);

            if(i != tempvec.size()-1){
                std::cout << ",";
            }
        }

        std::cout << "]" << std::endl;
    }
}

int main(){
    // node<int> test1;
    // node<int> test2(3);
    // //node<int> test3(3,-2);

    MyLinkedList<int> list1;
    list1.print();
    list1.addAtHead(2);
    list1.print();
    list1.addAtHead(4);
    list1.print();
    // list1.addAtTail(18);
    // list1.print();

    // MyLinkedList<int> list2;
    // list2.addAtTail(18);
    // list2.print();
}