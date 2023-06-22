#ifndef Node_H
#define Node_H

//Node.h
template <typename T>
class Node {
    private:
        T datum;
        Node<T>* next;
    public:
        Node();
        Node(T init);

        T GetData();
        Node<T>* GetNext();

        void SetData(T datum);
        void SetNext(Node<T>* nextdatum);
};

template <typename T>
Node<T>::Node(){
    datum = (T) NULL;
    next = nullptr;
}

template <typename T>
Node<T>::Node(T init){
    datum = init;
    next = nullptr;
}

template <typename T>
T Node<T>::GetData(){
    return datum;
}

template <typename T>
Node<T>* Node<T>::GetNext(){
    return next;
}

template <typename T>
void Node<T>::SetData(T datum){
    this -> datum = datum;
}

template <typename T>
void Node<T>::SetNext(Node<T>* nextdatum){
    this -> next = nextdatum;
}

#endif