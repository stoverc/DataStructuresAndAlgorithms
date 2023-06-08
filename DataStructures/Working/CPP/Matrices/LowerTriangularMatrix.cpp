#include <iostream>
#include "LowerTriangularMatrix.h"

//======================================================
//      CONSTRUCTORS
//======================================================
template <typename T>
LowerTriangularMatrix<T>::LowerTriangularMatrix(int size){
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
LowerTriangularMatrix<T>::~LowerTriangularMatrix(){
    delete [] A;
}

//======================================================
//      GETTERS
//======================================================
template <typename T>
T LowerTriangularMatrix<T>::Get(int i, int j){
    if(i < j){
        return 0;
    }
    else return A[(i*(i-1)/2)+j-1];
}

//======================================================
//      SETTERS
//======================================================
template <typename T>
void LowerTriangularMatrix<T>::Set(int i, int j, T x){
    if(i >= j){
        A[(i*(i-1)/2)+j-1] = x;
    }
}

//======================================================
//      NEEDED LATER
//======================================================

//======================================================
//      MEMBER FUNCTIONS
//======================================================
template <typename T>
void LowerTriangularMatrix<T>::ShortPrint(){
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
void LowerTriangularMatrix<T>::FullPrint(){
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
    LowerTriangularMatrix<int> m(4);
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

    LowerTriangularMatrix<int> m2(n);
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