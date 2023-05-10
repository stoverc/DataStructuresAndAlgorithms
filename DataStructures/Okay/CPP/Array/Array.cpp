#include <iostream>
#include "Array.h"

template <typename T>
Array<T>::Array(T* arr, int totalspace, int numelts){
    A =  arr;
    size = totalspace;
    length = numelts;

    for(int i = length; i < size; i++){
        A[i] = INT_MIN;
    }
}

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

int main () {
    //int init[5] = {2,4,6,8,10};
    Array<int> arr(new int[6]{2,4,6,8,10,12},20,6);
    arr.Display();

    arr.Append(25);
    arr.Display();

    arr.Insert(212,4);
    arr.Display();

    arr.Delete(2);
    arr.Display();
}