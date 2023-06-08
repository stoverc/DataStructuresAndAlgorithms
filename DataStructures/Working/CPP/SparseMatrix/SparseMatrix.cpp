//#include <iostream>
#include "Element.h"
#include "SparseArray.h"

template <typename T>
SparseMatrix<T>::SparseMatrix(int m, int n, int numElts){
    this -> m = m;
    this -> n = n;
    this -> numElts = numElts;

    ele = new Element<T>[this -> numElts];
}

template <typename T>
SparseMatrix<T>::~SparseMatrix(){
    delete [] ele;
}

template <typename T>
SparseMatrix<T> SparseMatrix<T>::operator+(SparseMatrix<T> &s){
    SparseMatrix<T> *sum;

    if(m != s.m || n != s.n){
        std::cout << "Dimensions do not match!" << std::endl;
    }

    sum = new SparseMatrix<T>(m,n,numElts+s.numElts);

    int i = 0, j = 0, k = 0;

    while(i < numElts && j < s.numElts){
        if(ele[i].i < s.ele[j].i){
            sum -> ele[k++] = ele[i++];
        }
        else if (ele[i].i > s.ele[j].i){
            sum -> ele[k++] = s.ele[j++];
        }
        else{
            if(ele[i].j < s.ele[j].j){
                sum -> ele[k++] = ele[i++];
            }
            else if(ele[i].j > s.ele[j].j){
                sum -> ele[k++] = s.ele[j++];
            }
            else{
                sum -> ele[k] = ele[i];
                sum -> ele[k++].x = ele[i++].x + s.ele[j++].x;
            }
        }
    }

    for(; i < numElts; i++){
        sum -> ele[k++] = ele[i];
    }

    for(; j < s.numElts; j++){
        sum -> ele[k++] = s.ele[j];
    }

    sum -> numElts = k;

    return *sum;
}

template <typename T>
inline std::istream & operator>>(std::istream &is, SparseMatrix<T> &s){
    std::cout << "Enter non-zero elements: " << std::endl;

    for(int i = 0; i < s.numElts; i++){
        std::cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
    }

    return is;
}

template <typename T>
inline std::ostream & operator<<(std::ostream &os, SparseMatrix<T> &s){
    int k = 0;

    for(int i = 0; i < s.m; i++){
        std::cout << "[";

        for(int j = 0; j < s.n; j++){
            if(i == s.ele[k].i && j == s.ele[k].j){
                if(j != s.n-1){
                    std::cout << s.ele[k++].x << " ";
                }
                else std::cout << s.ele[k++].x << "]";
            }
            else {
                if(j != s.n-1){
                    std::cout << "0 ";
                }
                else std::cout << "0]";
            }
        }

        std::cout << std::endl;
    }

    return os;
}

int main(){
    // SparseMatrix s1(5,5,5);
    // std::cin >> s1;
    // std::cout << s1;

    SparseMatrix<float> s2(5,5,5);
    SparseMatrix<float> s3(5,5,5);

    std::cin >> s2;
    std::cin >> s3;

    std::cout << "First matrix: " << std::endl;
    std::cout << s2;

    std::cout << "Second matrix: " << std::endl;
    std::cout << s3;

    SparseMatrix<float> sum = s2+s3;
    std::cout << "Their sum: " << std::endl;
    std::cout << sum;

    return 0;
}