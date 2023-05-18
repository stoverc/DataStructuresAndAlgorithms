#ifndef LowerTriangularMatrix_H
#define LowerTriangularMatrix_H

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class LowerTriangularMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================


//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class LowerTriangularMatrix
{
    private:
        T* A;
        int n;

    public:
        LowerTriangularMatrix(int n);
        ~LowerTriangularMatrix();
        void Set(int i, int j, T x);
        T Get(int i, int j);

        void ShortPrint();
        void FullPrint();
};

#endif