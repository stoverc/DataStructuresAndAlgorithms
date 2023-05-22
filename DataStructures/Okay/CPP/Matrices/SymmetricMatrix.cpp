#include <iostream>
#include "SymmetricMatrix.h"

//======================================================
//      CONSTRUCTORS
//======================================================
template <typename T>
SymmetricMatrix<T>::SymmetricMatrix(int size){
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
SymmetricMatrix<T>::~SymmetricMatrix(){
    delete [] A;
}

//======================================================
//      GETTERS
//======================================================
template <typename T>
T SymmetricMatrix<T>::Get(int i, int j){
    if(i < j){
        return this -> Get(j,i);
    }
    else return A[(i*(i-1)/2)+j-1];
}

//======================================================
//      SETTERS
//======================================================
template <typename T>
void SymmetricMatrix<T>::Set(int i, int j, T x){
    if(i >= j){
        A[(i*(i-1)/2)+j-1] = x;
    }
    else{
        this -> Set(j,i,x);
    }
}

//======================================================
//      NEEDED LATER
//======================================================

//======================================================
//      MEMBER FUNCTIONS
//======================================================
template <typename T>
void SymmetricMatrix<T>::ShortPrint(){
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
void SymmetricMatrix<T>::FullPrint(){
    for(int i = 1; i <= n; i++){
        std::cout << "[";

        for(int j = 1; j <= n; j++){
            if(i >= j){
                if(j != n){
                    std::cout << A[(i-1)*(i)/2+j-1] << " ";
                }
                else std::cout << A[(i-1)*(i)/2+j-1];
            }
            else {
                if(j != n){
                    std::cout << A[(j-1)*(j)/2+i-1] << " ";
                }
                else std::cout << A[(j-1)*(j)/2+i-1];
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
    SymmetricMatrix<int> m(4);
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

    SymmetricMatrix<int> m2(n);
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