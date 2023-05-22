#include <iostream>
#include "TridiagonalMatrix.h"

//======================================================
//      CONSTRUCTORS
//======================================================
template <typename T>
TridiagonalMatrix<T>::TridiagonalMatrix(int size){
    n = size;
    A = new T[3*size-2];

    for(int i = 0; i < 3*size-2; i++){
        A[i] = 0;
    }
}

//======================================================
//      DESTRUCTORS
//======================================================
template <typename T>
TridiagonalMatrix<T>::~TridiagonalMatrix(){
    delete [] A;
}

//======================================================
//      GETTERS
//======================================================
template <typename T>
T TridiagonalMatrix<T>::Get(int i, int j){
    if(std::abs(i-j) > 1){
        return 0;
    }
    else{//Lower Diag -> Main Diag -> Upper Diag
        if(i-j == 1){
            return A[j-1];
        }
        else if(i-j == 0){
            return A[n-1+j-1];
        }
        else {//if (i-j == -1){
            return A[2*n-1+i-1];
        }
    } 
}

//======================================================
//      SETTERS
//======================================================
template <typename T>
void TridiagonalMatrix<T>::Set(int i, int j, T x){
    if(std::abs(i-j) <= 1){//Lower Diag -> Main Diag -> Upper Diag
        if(i-j == 1){
            A[j-1] = x;
        }
        else if(i-j == 0){
            A[n-1+j-1] = x;
        }
        else {//(i-j == -1){
            A[2*n-1+i-1] = x;
        }
    }
}

//======================================================
//      NEEDED LATER
//======================================================

//======================================================
//      MEMBER FUNCTIONS
//======================================================
template <typename T>
void TridiagonalMatrix<T>::ShortPrint(){
    std::cout << "[";

    for(int i = 0; i < 3*n-2; i++){
        if(i != 3*n-2-1){
            std::cout << A[i] << ", ";
        }
        else{
            std::cout << A[i] << "]";
        }
    }

    std::cout << std::endl;
}

template <typename T>
void TridiagonalMatrix<T>::FullPrint(){
    for(int i = 1; i <= n; i++){
        std::cout << "[";

        for(int j = 1; j <= n; j++){
            if(std::abs(i-j) <= 1){
                if(j != n){
                    if(i-j == 1){
                        std::cout << A[j-1] << " ";
                    }
                    else if(i-j == 0){
                        std::cout << A[n-1+j-1] << " ";
                    }
                    else if (i-j == -1){
                        std::cout << A[2*n-1+i-1] << " ";
                    }
                }
                else{
                    if(i-j == 1){
                        std::cout << A[j-1];
                    }
                    else if(i-j == 0){
                        std::cout << A[n-1+j-1];
                    }
                    else if (i-j == -1){
                        std::cout << A[2*n-1+i-1];
                    }
                }
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
    TridiagonalMatrix<int> m(4);
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

    TridiagonalMatrix<int> m2(n);
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