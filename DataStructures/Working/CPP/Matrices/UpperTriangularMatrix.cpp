#include <iostream>
#include "UpperTriangularMatrix.h"

//======================================================
//      CONSTRUCTORS
//======================================================
template <typename T>
UpperTriangularMatrix<T>::UpperTriangularMatrix(int size){
    n = size;
    A = new T[size*(size+1)/2];

    for(int i = 0; i < size*(size+1)/2; i++){
        A[i] = 0;
    }
}

//======================================================
//      DESTRUCTORS
//======================================================
template <typename T>
UpperTriangularMatrix<T>::~UpperTriangularMatrix(){
    delete [] A;
}

//======================================================
//      GETTERS
//======================================================
template <typename T>
T UpperTriangularMatrix<T>::Get(int i, int j){
    if(i > j){
        return 0;
    }
    else return A[(i-1)*n-((i-2)*(i-1)/2)+(j-i)];
}

//======================================================
//      SETTERS
//======================================================
template <typename T>
void UpperTriangularMatrix<T>::Set(int i, int j, T x){
    if(i <= j){
        A[(i-1)*n-((i-2)*(i-1)/2)+(j-i)] = x;
    }
}

//======================================================
//      NEEDED LATER
//======================================================

//======================================================
//      MEMBER FUNCTIONS
//======================================================
template <typename T>
void UpperTriangularMatrix<T>::ShortPrint(){
    std::cout << "[";

    for(int i = 0; i < n*(n+1)/2; i++){
        if(i != n*(n+1)/2-1){
            std::cout << A[i] << ", ";
        }
        else{
            std::cout << A[i] << "]";
        }
    }

    std::cout << std::endl;
}

template <typename T>
void UpperTriangularMatrix<T>::FullPrint(){
    for(int i = 1; i <= n; i++){
        std::cout << "[";

        for(int j = 1; j <= n; j++){
            if(i <= j){
                if(j != n){
                    std::cout << A[(i-1)*n-((i-2)*(i-1))/2+(j-i)] << " ";
                }
                else std::cout << A[(i-1)*n-((i-2)*(i-1))/2+(j-i)];
            }
            else {
                if(j != n){
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
    UpperTriangularMatrix<int> m(4);
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

    UpperTriangularMatrix<int> m2(n);
    m2.ShortPrint();

    std::cout << std::endl << "Enter all elements: " << std::endl;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            std::cin >> x;
            m2.Set(i,j,x);
        }
    }

    m2.FullPrint();
}