#include <iostream>
#include "DiagonalMatrix.h"

//======================================================
//      CONSTRUCTORS
//======================================================
template <typename T>
DiagonalMatrix<T>::DiagonalMatrix(int size){
    n = size;
    A = new T[size];

    for(int i = 0; i < size; i++){
        A[i] = 0;
    }
}

//======================================================
//      DESTRUCTORS
//======================================================
template <typename T>
DiagonalMatrix<T>::~DiagonalMatrix(){
    delete [] A;
}

//======================================================
//      GETTERS
//======================================================
template <typename T>
T DiagonalMatrix<T>::Get(int i, int j){
    if(i != j){
        return 0;
    }
    else return A[i];
}

//======================================================
//      SETTERS
//======================================================
template <typename T>
void DiagonalMatrix<T>::Set(int i, int j, T x){
    if(i == j){
        A[i] = x;
    }
}

//======================================================
//      NEEDED LATER
//======================================================

//======================================================
//      MEMBER FUNCTIONS
//======================================================
template <typename T>
void DiagonalMatrix<T>::ShortPrint(){
    std::cout << "[";

    for(int i = 0; i < n; i++){
        if(i != n-1){
            std::cout << A[i] << ", ";
        }
        else{
            std::cout << A[i] << "]";
        }
    }

    std::cout << std::endl;
}

template <typename T>
void DiagonalMatrix<T>::FullPrint(){
    for(int i = 0; i < n; i++){
        std::cout << "[";

        for(int j = 0; j < n; j++){
            if(i == j){
                if(j != n-1){
                    std::cout << A[i] << " ";
                }
                else std::cout << A[i];
            }
            else {
                if(j != n-1){
                    std::cout << "0 ";
                }
                else std::cout << "0";
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
    DiagonalMatrix<int> m(4);
    m.ShortPrint();

    m.Set(2,2,3);
    m.Set(3,3,-2);
    m.ShortPrint();
    m.FullPrint();

    std::cout << m.Get(2,2);
}