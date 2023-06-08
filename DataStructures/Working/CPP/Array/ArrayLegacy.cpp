#include <iostream>
#include "Array.h"

template <typename T>
void LegacyUnion(Array<T> arr1, Array<T> arr2){
    T* a1 = arr1.GetArray();
    T* a2 = arr2.GetArray();
    T a3[arr1.GetSize() + arr2.GetSize()];

    for(int i = 0; i < arr1.GetLength(); i++){
        a3[i] = a1[i];
    }

    int k = arr1.GetLength();

    for(int i = 0; i < arr2.GetLength(); i++){
        if(!Contains(a3,sizeof(a3)/sizeof(T),a2[i])){
            a3[k] = a2[i];
            k += 1;
        }
    }

    Array<T> arr3(a3,arr1.GetSize()+arr2.GetSize(),k);

    arr3.Display();
}

template <typename T>
void LegacyIntersection(Array<T> arr1, Array<T> arr2){
    T* a1 = arr1.GetArray();
    T* a2 = arr2.GetArray();
    T a3[arr1.GetSize() + arr2.GetSize()];
    T a4[arr1.GetSize() + arr2.GetSize()];

    for(int i = 0; i < arr1.GetLength(); i++){
        a3[i] = a1[i];
    }

    int k1 = arr1.GetLength();
    int k2 = 0;

    for(int i = 0; i < arr2.GetLength(); i++){
        if(!Contains(a3,sizeof(a3)/sizeof(T),a2[i])){
            a3[k1] = a2[i];
            k1 += 1;
        }
    }

    for(int i = 0; i < k1; i++){
        if(Contains(a1,arr1.GetLength(),a3[i]) && Contains(a2,arr2.GetLength(),a3[i])){
            a4[k2]=a3[i];
            k2++;
        }
    }

    Array<T> arr3(a4,std::max(arr1.GetSize(),arr2.GetSize()),k2);

    arr3.Display();
}

template <typename T>
void LegacyIntersection2(Array<T> arr1, Array<T> arr2){
    T* a1 = arr1.GetArray();
    T* a2 = arr2.GetArray();
    T a3[arr1.GetSize() + arr2.GetSize()];

    int k1 = 0;

    for(int i = 0; i < arr1.GetLength(); i++){
        if(Contains(a2,arr2.GetLength(),a1[i])){
            a3[k1] = a1[i];
            k1 += 1;
        }
    }

    Array<T> arr3(a3,std::min(arr1.GetSize(),arr2.GetSize()),k1);

    arr3.Display();
}

template <typename T>
void LegacyComplement(Array<T> arr1, Array<T> arr2){
    T* a1 = arr1.GetArray();
    T* a2 = arr2.GetArray();
    T a3[arr1.GetSize() + arr2.GetSize()];

    int k1 = 0;

    for(int i = 0; i < arr1.GetLength(); i++){
        if(!Contains(a2,arr2.GetLength(),a1[i])){
            a3[k1] = a1[i];
            k1 += 1;
        }
    }

    Array<T> arr3(a3,arr1.GetSize(),k1);

    arr3.Display();
}