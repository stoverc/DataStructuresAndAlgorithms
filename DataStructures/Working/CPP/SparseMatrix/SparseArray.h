#ifndef SparseArray_H
#define SparseArray_H

#include <iostream>

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class SparseMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================
template <typename T> std::istream & operator>>(std::istream &is, SparseMatrix<T> &s); 
template <typename T> std::ostream & operator<<(std::ostream &os, SparseMatrix<T> &s);

//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class SparseMatrix{
    private:
        int m; 
        int n;
        int numElts;
        Element<T> *ele;

    public:
        SparseMatrix(int m, int n, int numElts);
        ~SparseMatrix();

        SparseMatrix operator+(const SparseMatrix &s);

        friend std::istream & operator>><T>(std::istream &is, SparseMatrix &s);
        friend std::ostream & operator<<<T>(std::ostream &os, SparseMatrix &s);
};

#endif