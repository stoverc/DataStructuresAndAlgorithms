#ifndef TridiagonalMatrix_H
#define TridiagonalMatrix_H

//======================================================
//      PRE-DEFINE CLASS
//======================================================
template <typename T>
class TriBandMatrix;

//======================================================
//      FRIEND FUNCTIONS
//======================================================


//======================================================
//      CLASS DEF
//======================================================
template <typename T>
class TridiagonalMatrix
{
    private:
        T* A;
        int n;

    public:
        TridiagonalMatrix(int n);
        ~TridiagonalMatrix();
        void Set(int i, int j, T x);
        T Get(int i, int j);

        void ShortPrint();
        void FullPrint();
};

#endif