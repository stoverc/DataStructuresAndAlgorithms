#include <iostream>
#include "Array.h"

template <typename T>
Array<T>::Array(T* arr, int totalspace, int numelts){
    A = arr;
    size = totalspace;
    length = numelts;

    for(int i = length; i < size; i++){
        A[i] = INT_MIN;
    }
}

//template <typename T>
//Array<T>::~Array(){
//    A = nullptr;
//    delete A;
    //std::cout << "\n Destructor executed";
//}

template <typename T>
void Array<T>::Display(){
    std::cout << "[";

    for(int i = 0; i < length; i++){
        if(i != length-1){
            std::cout << A[i] << ", ";
        }
        else{
            std::cout << A[i] << "]";
        }
    }

    std::cout << std::endl;
}

template <typename T>
void Array<T>::Append(T x){
    if(length < size){
        A[length] = x;
        length += 1;
    }
    else {
        std::cout << "There isn't enough room to append." << std::endl;
    }
}

template <typename T>
void Array<T>::Insert(T x, int ind){
    if(ind >= 0 && ind < length){
        if(length < size){
            for(int i = length; i > ind; i--){
                A[i] = A[i-1];
            }

            A[ind] = x;
            length += 1;
        }
        else {
            std::cout << "There isn't enough room to insert." << std::endl;
        }
    }
}

template <typename T>
void Array<T>::Delete(int ind){
    if(ind >= 0 && ind < length){
        for(int i = ind; i < length-1; i++){
            A[i] = A[i+1];
        }

        A[length-1] = INT_MIN;
        length -= 1;
    }
}

template <typename T>
int Array<T>::LinearSearch(T x){
    for(int i = 0; i < length; i++){
        if(A[i]==x){
            return i;
        }
    }

    return -1;
}

template <typename T>
int Array<T>::BinarySearch(T x){
    int l = 0, h = length-1, mid;

    while(l <= h){
        mid = (l+h)/2;

        if(x == A[mid]){
            return mid;
        }
        else if(x < A[mid]){
            h = mid-1;
        }
        else{
            l = mid+1;
        }
    }

    return -1;
}

template <typename T>
T Array<T>::Get(int ind){
    if(ind >= 0 && ind < length){
        return A[ind];
    }
    else{
        std::cout << std::endl << "Array out of bounds." << std::endl;
    }

    return (T)INT_MIN;
}

template <typename T>
void Array<T>::Set(T x, int ind){
    if(ind >= 0 && ind < length){
        A[ind] = x;
    }
    else{
        std::cout << std::endl << "Array out of bounds." << std::endl;
    }
}

template <typename T>
T Array<T>::Sum(){
    T sum = 0;

    for(int i = 0; i < length; i++){
        sum += A[i];
    }

    return sum;
}

template <typename T>
float Array<T>::Avg(){
    return (float)(this->Sum())/length;
}

template <typename T>
T Array<T>::Max(){
    int max = INT_MIN;

    for(int i = 0; i < length; i++){
        if(max < A[i]){
            max = A[i];
        }
    }

    return max;
}

template <typename T>
T Array<T>::Min(){
    int min = INT_MAX;

    for(int i = 0; i < length; i++){
        if(min > A[i]){
            min = A[i];
        }
    }

    return min;
}

int main () {
    int *init = new int[6]{2,4,6,8,10,12}; 
    int *init2 = new int[8]{2,4,6,8,10,12,25,212};

    Array<int> arr(init,20,6);
    Array<int> arr2(init2,20,8);

    arr.Display();
    arr2.Display();

    arr.Append(25);
    arr.Display();

    arr.Insert(212,4);
    arr.Display();

    arr.Delete(2);
    arr.Display();

    std::cout << arr.LinearSearch(8) << " " << arr.LinearSearch(61) << std::endl;
    std::cout << arr2.BinarySearch(8) << " " << arr2.BinarySearch(61) << std::endl;

    arr.Display();
    std::cout << arr.Get(3) << " " << arr.Sum() << " " << arr.Avg() << " " << arr.Min() << " " << arr.Max() << std::endl;

    arr.Set(99,3);
    arr.Display();
    std::cout << arr.Get(3) << " " << arr.Sum() << " " << arr.Avg() << " " << arr.Min() << " " << arr.Max() << std::endl;
}