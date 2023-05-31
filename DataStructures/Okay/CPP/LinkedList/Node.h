#ifndef Node_H
#define Node_H

//Node.h
template <typename T>
class Node {
    private:
        T datum;
        Node<T>* next;
    public:
        Node<T>();
        Node<T>(T init);

        T GetData();
        Node<T>* GetNext();
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

#endif