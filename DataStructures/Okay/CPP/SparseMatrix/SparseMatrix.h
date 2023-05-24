#ifndef SparseMatrix_H
#define SparseMatrix_H

#include <iostream>

//======================================================
//      PRE-DEFINE CLASS
//======================================================
//template <typename T>
class Element{
    public:
        int i;
        int j;
        int x;
};

//template <typename T>
class SparseMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================

//======================================================
//      CLASS DEF
//======================================================
//template <typename T>
class SparseMatrix{
    private:
        int m;
        int n;
        int numElts;
        struct Element *ele;

    public:
        SparseMatrix(int m, int n, int numElts);
        ~SparseMatrix();
        SparseMatrix operator+(SparseMatrix &s);

        //======================================================
        //      FRIEND FUNCTIONS
        //======================================================
        friend std::istream & operator>>(std::istream &is, SparseMatrix &s);
        friend std::ostream & operator<<(std::ostream &os, SparseMatrix &s);
};

#endif