#ifndef UpperTriangularMatrix_H
#define UpperTriangularMatrix_H

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class UpperTriangularMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================


//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class UpperTriangularMatrix
{
    private:
        T* A;
        int n;

    public:
        UpperTriangularMatrix(int n);
        ~UpperTriangularMatrix();
        void Set(int i, int j, T x);
        T Get(int i, int j);

        void ShortPrint();
        void FullPrint();
};

#endif