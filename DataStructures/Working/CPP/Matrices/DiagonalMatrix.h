#ifndef DiagonalMatrix_H
#define DiagonalMatrix_H

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class DiagonalMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================


//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class DiagonalMatrix
{
    private:
        T* A;
        int n;

    public:
        DiagonalMatrix(int n);
        void Set(int i, int j, T x);
        T Get(int i, int j);

        void ShortPrint();
        void FullPrint();
};

#endif