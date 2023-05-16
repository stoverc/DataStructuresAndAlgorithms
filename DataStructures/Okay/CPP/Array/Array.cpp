#include <iostream>
#include "Array.h"

//======================================================
//      CONSTRUCTORS
//======================================================
template <typename T>
Array<T>::Array(){
    size = 10;
    length = 0;
    A = new T[size];
}

template <typename T>
Array<T>::Array(int arrsize){
    size = arrsize;
    length = 0;
    A = new T[size];
}

template <typename T>
Array<T>::Array(int arrsize, int arrlength){
    size = arrsize;
    length = arrlength;
    A = new T[size];
}

template <typename T>
Array<T>::Array(T* arr, int arrsize, int arrlength){
    A = arr;
    size = arrsize;
    length = arrlength;

    for(int i = length; i < size; i++){
        A[i] = INT_MIN;
    }
}

//======================================================
//      GETTERS
//======================================================
template <typename T>
T* Array<T>::GetArray(){
    return this -> A;
}

template <typename T>
int Array<T>::GetSize(){
    return this -> size;
}

template <typename T>
int Array<T>::GetLength(){
    return this -> length;
}

//======================================================
//      SETTERS
//======================================================
template <typename T>
void Array<T>::SetArray(int ind, T x){
    if(0 <= ind && ind <= size){
        A[ind] = x;
    }
}

template <typename T>
void Array<T>::SetSize(int arrsize){
    size = arrsize;
}

template <typename T>
void Array<T>::SetLength(int arrlength){
    length = arrlength;
}

//======================================================
//      MEMBER FUNCTIONS
//======================================================
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
void Array<T>::Insert(int ind, T x){
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

    return INT_MIN;
}

template <typename T>
void Array<T>::Set(int ind, T x){
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
        if(A[i] > max){
            max = A[i];
        }
    }

    return max;
}

template <typename T>
T Array<T>::Min(){
    int min = INT_MAX;

    for(int i = 0; i < length; i++){
        if(A[i] < min){
            min = A[i];
        }
    }

    return min;
}

template <typename T>
void Array<T>::Reverse(){
    T B[length];

    for(int i = 0; i < length; i++){
        B[i] = A[length-i-1];
    }

    for(int i = 0; i < length; i++){
        A[i] = B[i];
    }

    //delete B;
}

template <typename T>
void Array<T>::LeftShift(){
    for(int i = 1; i < length; i++){
        A[i-1] = A[i];
    }

    length -= 1;
}

template <typename T>
void Array<T>::LeftRotate(){
    T temp = A[0];

    LeftShift();
    length += 1;
    A[length-1] = temp;
}

template <typename T>
void Array<T>::RightShift(){
    for(int i = length-1; i > 0; i--){
        A[i] = A[i-1];
    }

    A[0] = INT_MIN;
    length += 1;
}

template <typename T>
void Array<T>::RightRotate(){
    T temp = A[length-1];

    RightShift();
    length -= 1;
    A[0] = temp;
}

template <typename T>
void Array<T>::SortedInsert(T x){
    int i = length - 1;

    while(A[i] > x){
        A[i+1]=A[i];
        i--;
    }

    A[i+1] = x;

    length += 1;
}

template <typename T>
bool Array<T>::IsSorted(){
    for(int i = 0; i < length-1; i++){
        if(A[i] > A[i+1]){
            return false;
        }
    }

    return true;
}

template <typename T>
void Array<T>::PosNegSwap(){
    int i = 0, j = length - 1;
    T temp;

    while(i < j){
        while(A[i] < 0){
            i++;
        }

        while(A[j] >= 0){
            j--;
        }

        if(i < j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
}

template <typename T>
Array<T>* Array<T>::Union(Array<T> *arr2){
    T* a1 = A;
    T* a2 = arr2 -> A;
    T a3[size + arr2 -> GetSize()];
    
    for(int i = 0; i < length; i++){
        a3[i] = a1[i];
    }

    int k = length;

    for(int i = 0; i < arr2 -> GetLength(); i++){
        if(!Contains(a3,sizeof(a3)/sizeof(T),a2[i])){
            a3[k] = a2[i];
            k += 1;
        }
    }

    Array<T> *arr3 = new Array<T>(size + arr2 -> GetSize(), k);

    for(int i = 0; i < sizeof(a3)/sizeof(T); i++){
        arr3 -> A[i] = a3[i];
    }

    return arr3;
}

//======================================================
//      NON-MEMBER FUNCTIONS
//======================================================
template <typename T>
bool Contains(T arr[], int size, T x){
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return 1;
        }
    }
    return 0;
}

template <typename T>
void CartesianProduct(Array<T> arr1, Array<T> arr2){
    T* a1 = arr1.GetArray();
    T* a2 = arr2.GetArray();
    T a3[arr1.GetSize() * arr2.GetSize()][2];

    int k1 = 0;

    for(int i = 0; i < arr1.GetLength(); i++){
        for(int j = 0; j < arr2.GetLength(); j++){
            a3[k1][0] = a1[i];
            a3[k1][1] = a2[j];
            k1++;
        }
    }

    std::cout << "[";

    for(int i = 0; i < arr1.GetLength()*arr2.GetLength(); i++){
        if(i != arr1.GetLength()*arr2.GetLength()-1){
            std::cout << "[" << a3[i][0] << "," << a3[i][1] << "],";
        }
        else{
            std::cout << "[" << a3[i][0] << "," << a3[i][1] << "]";
        }
    }

    std::cout << "]";
}

//======================================================
//      SANDBOX
//======================================================
template <typename T>
Array<T>* Union(Array<T> *arr1, Array<T> *arr2){
    T* a1 = (*arr1).GetArray();
    T* a2 = (*arr2).GetArray();
    T a3[(*arr1).GetSize() + (*arr2).GetSize()];

    for(int i = 0; i < (*arr1).GetLength(); i++){
        a3[i] = a1[i];
    }

    int k = (*arr1).GetLength();

    for(int i = 0; i < (*arr2).GetLength(); i++){
        if(!Contains(a3,sizeof(a3)/sizeof(T),a2[i])){
            a3[k] = a2[i];
            k += 1;
        }
    }

    Array<T> *arr3 = new Array<T>((*arr1).GetSize() + (*arr2).GetSize(), k);

    for(int i = 0; i < sizeof(a3)/sizeof(T); i++){
        arr3 -> SetArray(i,a3[i]);
    }

    return arr3;
}

template <typename T>
Array<T>* Intersection(Array<T> *arr1, Array<T> *arr2){
    T* a1 = (*arr1).GetArray();
    T* a2 = (*arr2).GetArray();
    T a3[(*arr1).GetSize() + (*arr2).GetSize()];

    int k1 = 0;

    for(int i = 0; i < (*arr1).GetLength(); i++){
        if(Contains(a2,(*arr2).GetLength(),a1[i])){
            a3[k1] = a1[i];
            k1 += 1;
        }
    }

    Array<T> *arr3 = new Array<T>(std::min((*arr1).GetSize(),(*arr2).GetSize()),k1);

    for(int i = 0; i < sizeof(a3)/sizeof(T); i++){
        arr3 -> SetArray(i,a3[i]);
    }

    return arr3;
}

template <typename T>
Array<T>* Complement(Array<T> *arr1, Array<T> *arr2){
    T* a1 = (*arr1).GetArray();
    T* a2 = (*arr2).GetArray();
    T a3[(*arr1).GetSize() + (*arr2).GetSize()];

    int k1 = 0;

    for(int i = 0; i < (*arr1).GetLength(); i++){
        if(!Contains(a2,(*arr2).GetLength(),a1[i])){
            a3[k1] = a1[i];
            k1 += 1;
        }
    }

    Array<T> *arr3 = new Array<T>((*arr1).GetSize(),k1);

    for(int i = 0; i < sizeof(a3)/sizeof(T); i++){
        arr3 -> SetArray(i,a3[i]);
    }

    return arr3;
}

//======================================================
//      MAIN
//======================================================
int main () {
    int *init = new int[6]{2,4,6,8,10,12}; 
    int *init2 = new int[8]{2,4,6,8,10,12,25,212};

    Array<int> arr(init,20,6);
    Array<int> arr2(init2,20,8);

    arr.Display();
    arr2.Display();

    arr.Append(25);
    arr.Display();

    arr.Insert(4,212);
    arr.Display();

    arr.Delete(2);
    arr.Display();

    std::cout << arr.LinearSearch(8) << " " << arr.LinearSearch(61) << std::endl;
    std::cout << arr2.BinarySearch(8) << " " << arr2.BinarySearch(61) << std::endl;

    arr.Display();
    std::cout << arr.Get(3) << " " << arr.Sum() << " " << arr.Avg() << " " << arr.Min() << " " << arr.Max() << std::endl;

    arr.Set(3,99);
    arr.Display();
    std::cout << arr.Get(3) << " " << arr.Sum() << " " << arr.Avg() << " " << arr.Min() << " " << arr.Max() << std::endl;

    arr.Reverse();
    arr.Display();

    arr.LeftShift();
    arr.Display();

    arr.RightShift();
    arr.Display();

    arr.LeftRotate();
    arr.Display();

    arr2.Display();
    arr2.RightRotate();
    arr2.Display();
    arr2.LeftRotate();
    arr2.Display();

    arr2.SortedInsert(9);
    arr2.Display();

    arr.Display();
    std::cout << std::boolalpha <<  arr.IsSorted() << std::endl;
    arr2.Display();
    std::cout << std::boolalpha << arr2.IsSorted() << std::endl;

    int *init3 = new int[14]{-2,4,-6,8,-10,12,0,-25,212,-44,-99,23,17,7};
    Array<int> arr3(init3,20,14);
    arr3.Display();
    arr3.PosNegSwap();
    arr3.Display();

    int *init4 = new int[10]{-2,2,4,9,212,300,400,500,600,3125};
    Array<int> arr4(init4,20,10);
    std::cout << std::endl << "This is arr2: " << std::endl;
    arr2.Display();
    std::cout << "This is arr4: " << std::endl;
    arr4.Display();

    std::cout << "The (unsorted) union of arr2 and arr4: " << std::endl;
    (*(Union(&arr2,&arr4))).Display();
    std::cout << "The intersection of arr2 and arr4: " << std::endl;
    (*(Intersection(&arr2,&arr4))).Display();
    std::cout << "The complement arr2-arr4: " << std::endl;
    (*(Complement(&arr2,&arr4))).Display();
    std::cout << "The complement arr4-arr2: " << std::endl;
    (*(Complement(&arr4,&arr2))).Display();
    //std::cout << "The Cartesian product arr2xarr4: " << std::endl;
    //CartesianProduct(arr2,arr4);
    //std::cout << std::endl;

    //(*(Union(&arr2,&arr4))).Display();
    //(*(arr2.Union(&arr4))).Display();
}