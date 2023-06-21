#include <iostream>

template <typename T>
class Stack {
    private:
        int size;
        T* data;
        int top;
    public:
        Stack();
        Stack(int n);

        ~Stack();

        void Display();
        void Push(T x);
        T Pop();
};

template <typename T>
Stack<T>::Stack(){
    size = 0;
    data = new T[size];
    top = -1;
}

template <typename T>
Stack<T>::Stack(int n){
    size = n;
    data = new T[size];
    top = -1;
}

template <typename T>
Stack<T>::~Stack(){
    delete [] data;
    top = -1;
}

template <typename T>
void Stack<T>::Display(){
    if(top == -1){
        std::cout << "[]" << std::endl;
    }
    else{
        std::cout << "[";

        for(int i = top; i >= 0; i--){
            if(i > 0){
                std::cout << data[i] << ",";
            }
            else{
                std::cout << data[i] << "]" << std::endl;
            }
        }
    }
}

template <typename T>
void Stack<T>::Push(T x){
    if(top == size-1){
        std::cout << "Stack overflow!" << std::endl;
    }
    else{
        top++;
        data[top]=x;
    }
}

// template <typename T>
// T* Stack<T>::Pop(){
//     if(top == -1){
//         std::cout << "Stack underflow!" << std::endl;
//         return NULL;
//     }
//     else{
//         return &(data[top--]);
//     }
// }

template <typename T>
T Stack<T>::Pop(){
    if(top == -1){
        std::cout << "Stack underflow!" << std::endl;
        return (T) NULL;
    }
    else{
        return data[top--];
    }
}

int main(){
    Stack<int> ll1(5);
    ll1.Push(10);
    ll1.Push(20);
    //ll1.Push(30);
    //ll1.Push(40);
    //ll1.Push(50);

    ll1.Display();

    std::cout << "Popping: " << ll1.Pop() << std::endl;
    ll1.Display();
    std::cout << "Popping: " << ll1.Pop() << std::endl;
    ll1.Display();
    std::cout << "Popping: " << ll1.Pop() << std::endl;
    ll1.Display();

    return 0;
}