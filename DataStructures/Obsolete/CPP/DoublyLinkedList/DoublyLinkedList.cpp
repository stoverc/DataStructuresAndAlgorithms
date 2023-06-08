#include <iostream>
#include <limits>           // allows NaN type
#include <cmath>            // allows std::isnan()
#include <vector>

template <typename T>
class node{
    public:
        T data;             // Find a way to make private?
        node<T>* next;      // Ditto?
        node<T>* prev;
        node<T>();
        node<T>(T datum);
};

template <typename T>
node<T>::node(){
    data = std::nan("1");
    next = NULL;
    prev = NULL;
}

template <typename T>
node<T>::node(T datum){
    data = datum;
    next = NULL;
    prev = NULL;
}

template <typename T>
class MyLinkedList{
    public:
        MyLinkedList<T>();
        void addAtHead(T val);
        void addAtTail(T val);
        void addAtIndex(int index, T val);
        T get(int index);
        void deleteAtIndex(int index);
        int length();
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

    std::cout << "The new head is: " << (*head).data << std::endl;
}

template <typename T>
void MyLinkedList<T>::addAtTail(T val){
    node<T>* new_node = new node(val);

    if(head == NULL){
        head = new_node;
    } else{
        node<T>* curr = head;

        while((*curr).next != NULL){
            curr = (*curr).next;
        }

        node<T>* old_prev = curr;

        (*curr).next = new_node;
        (*curr).prev = old_prev;

        std::cout << "The new tail is: " << (*curr).next->data << std::endl;
        std::cout << "Its previous is: " << (*curr).prev->data << std::endl;
    }
}

template <typename T>
void MyLinkedList<T>::addAtIndex(int index, T val){
    node<T>* new_node = new node(val);

    if(index < 0 || index >= length()){
        std::cout << "Invalid insertion at position " << index << " requested." << std::endl;
        return;
    }

    if(index == 0){
        addAtHead(val);
        return;
    } 

    int count = 0;
    node<T>* curr = head;

    while((*curr).next != NULL){
        if(count == index-1){
            (*new_node).next = (*curr).next;
            (*new_node).prev = (*curr).prev;
            (*curr).next = new_node;

            std::cout << "At index " << index << ", the item is: " << (*curr).next->data << std::endl;
            std::cout << "Its previous is: " << (*curr).prev->data << std::endl;

            return;
        }
        
        curr = (*curr).next;
        count++;
    }
}

template <typename T>
T MyLinkedList<T>::get(int index){
    if(index < 0 || index >= length()){
        std::cout << "Invalid item at position " << index << " requested." << std::endl;
        return -1;
    }

    if(index == 0){
        std::cout << "The item at index " << index << " is: ";
        return (*head).data;
    } 

    int count = 0;
    node<T>* curr = head;

    while((*curr).next != NULL){
        if(count == index){
            std::cout << "The item at index " << index << " is: ";
            return (*curr).data;
        }
        
        curr = (*curr).next;
        count++;
    }

    return -1;
}

template <typename T>
void MyLinkedList<T>::deleteAtIndex(int index){
    node<T>* temp = head;
    node<T>* curr;
    int i = 0;

    if(head == NULL){
        std::cout << "List is empty; cannot delete." << std::endl;
    }

    if(i==index){
        head = (*temp).next;
        std::cout << "The new item at index " << index << " is " << (*head).data << std::endl;
        return;
    }

    while(temp != NULL){
        if(i==index){
            break;
        }

        i+=1;
        curr = temp;
        temp = (*temp).next;
    }

    if(temp == NULL){
        return;
    }

    (*curr).next = (*temp).next;
    (*curr).prev = (*temp).prev;
    std::cout << "The new item at index " << index << " is " << (*curr).next->data << std::endl;
    std::cout << "Its previous is: " << (*curr).prev->data << std::endl;
}

template <typename T>
int MyLinkedList<T>::length(){
    int len = 0;
    node<T>* curr = head;

    if(curr == NULL){
        return len;
    } else {
        while((*curr).next != NULL){
            len++;
            curr = (*curr).next;
        }
    }

    return len+1;
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
    std::cout << list1.length() << std::endl;
    list1.addAtHead(2);
    list1.print();
    std::cout << list1.length() << std::endl;
    list1.addAtHead(4);
    list1.print();
    std::cout << list1.length() << std::endl;
    list1.addAtTail(18);
    list1.print();
    std::cout << list1.length() << std::endl;
    list1.addAtTail(-21);
    list1.print();
    std::cout << list1.length() << std::endl;
    list1.addAtIndex(2,42);
    list1.print();
    std::cout << list1.length() << std::endl;
    list1.addAtIndex(0,666);
    list1.print();
    std::cout << list1.length() << std::endl;
    std::cout << list1.get(0) << std::endl;
    std::cout << list1.get(1) << std::endl;
    std::cout << list1.get(4) << std::endl;
    std::cout << list1.get(-2) << std::endl;
    std::cout << list1.get(14) << std::endl;
    list1.deleteAtIndex(0);
    list1.print();
    list1.deleteAtIndex(2);
    list1.print();

    // MyLinkedList<int> list2;
    // list2.addAtTail(18);
    // list2.print();
}