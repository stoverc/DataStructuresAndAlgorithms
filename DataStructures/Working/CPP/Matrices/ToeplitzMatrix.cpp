#include <iostream>
#include "ToeplitzMatrix.h"

//======================================================
//      CONSTRUCTORS
//======================================================
template <typename T>
ToeplitzMatrix<T>::ToeplitzMatrix(int size){
    n = size;
    A = new T[2*size-1];

    for(int i = 0; i < 2*size-1; i++){
        A[i] = 0;
    }
}

//======================================================
//      DESTRUCTORS
//======================================================
template <typename T>
ToeplitzMatrix<T>::~ToeplitzMatrix(){
    delete [] A;
}

//======================================================
//      GETTERS
//======================================================
template <typename T>
T ToeplitzMatrix<T>::Get(int i, int j){
    if(i <= j){
        return A[j-i];
    }
    else return A[n+i-j-1];
}

//======================================================
//      SETTERS
//======================================================
template <typename T>
void ToeplitzMatrix<T>::Set(int i, int j, T x){
    if(i <= j){
        A[j-i] = x;
    }
    else A[n+i-j-1] = x;
}

//======================================================
//      NEEDED LATER
//======================================================

//======================================================
//      MEMBER FUNCTIONS
//======================================================
template <typename T>
void ToeplitzMatrix<T>::ShortPrint(){
    std::cout << "[";

    for(int i = 0; i < 2*n-1; i++){
        if(i != 2*n-1-1){
            std::cout << A[i] << ", ";
        }
        else{
            std::cout << A[i] << "]";
        }
    }

    std::cout << std::endl;
}

template <typename T>
void ToeplitzMatrix<T>::FullPrint(){
    for(int i = 1; i <= n; i++){
        std::cout << "[";

        for(int j = 1; j <= n; j++){
            if(i <= j){
                if(j != n){
                    std::cout << A[j-i] << " ";
                }
                else std::cout << A[j-i];
            }
            else {
                if(j != n){
                    std::cout << A[n+i-j-1] << " ";
                }
                else std::cout << A[n+i-j-1];
            }
        }

        std::cout << "]" << std::endl;
    }
}

//======================================================
//      NON-MEMBER FUNCTIONS
//======================================================

//======================================================
//      MAIN
//======================================================
int main(){
    ToeplitzMatrix<int> m(4);
    m.ShortPrint();

    m.Set(2,2,3);
    m.Set(3,1,11);
    m.Set(3,3,-2);
    m.ShortPrint();
    m.FullPrint();

    std::cout << m.Get(2,2) << std::endl;

    int n, x;

    std::cout << std::endl << "Enter dimension: ";
    std::cin >> n;

    ToeplitzMatrix<int> m2(n);
    m2.ShortPrint();

    std::cout << std::endl << "Enter all elements: " << std::endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            std::cin >> x;
            m2.Set(i,j,x);
        }
    }

    m2.FullPrint();
    m2.ShortPrint();
}